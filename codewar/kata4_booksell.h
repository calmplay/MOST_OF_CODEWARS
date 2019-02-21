#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<map>

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//KATA1: Help the bookseller !
/*-------------------------------------------------------------

A bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more capitals letters. The 1st letter of a code is the capital letter of the book category. In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.

For example an extract of one of the stocklists could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or

L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

M = {"A", "B", "C", "W"}
or

M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.

For the lists L and M of example you have to return the string (in Haskell/Clojure a list of pairs):

(A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.

If L or M are empty return string is "" (Clojure should return an empty array instead).

Note:

In the result codes and their values are in the same order as in M.

*/


//my function

class StockList
{
public:
static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);//art means 作品 here
};


std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
{    
    //这里是改动后的逻辑:因为最后要求返回的string要按此顺序输出,故复制并保留原categories的字母顺序；
    //然而就算没有这个需求，从程序的安全考虑也应该这么做！
    std::vector<std::string> lstOfArt_2 = lstOfArt;
    std::vector<std::string> categories_2 = categories;
    std::sort(lstOfArt_2.begin(), lstOfArt_2.end());
    std::sort(categories_2.begin(), categories_2.end());

    //map是无序的，因此无法用它来记忆原categories_2的字母顺序
    std::map<std::string, int> map_cat;//用于将{"A","C","D"...}转化为{("A",20),("C",23),("D",38)...}

    std::vector<std::string>::iterator itrt_artlst = lstOfArt_2.begin();//用于遍历排序后的作品清单
    std::vector<std::string>::iterator itrt_cat = categories_2.begin();//用于遍历排序后的首字母目录清单

    //std::regex reg1("\\d+");//\\用于转义 故此式等价于式子：\d+
    std::regex reg1("\\d+");
    std::smatch r1;

    std::string ret = "";

    for (; itrt_cat != categories_2.end(); itrt_cat++)
    {
        map_cat[*itrt_cat] = 0;
        //ret += "(" + (*itrt_cat) + " : ";//因为上面的特定需求及改动，不在此循环里拼接字符串，因为顺序是不对的


        //for (; itrt_artlst != lstOfArt_2.end(); itrt_artlst++)//①②两处为新的改动，非常重要！！
        for (; itrt_artlst != lstOfArt_2.end(); )//★①   
        {
            if ((*itrt_artlst).substr(0, 1) == (*itrt_cat))
            {
                std::regex_search(*itrt_artlst, r1, reg1);
                map_cat[*itrt_cat] += atoi(r1.str().c_str());//string转int
                itrt_artlst++;//★②      
            }
            else
            {
                break;
            }
        }

        //因为上面的特定需求及改动，不在此循环里拼接字符串，因为顺序是不对的
        //ret += std::to_string(map_cat[*itrt_cat]) + ")";
        //if ((itrt_cat+1) != categories_2.end())
        //{
        //    ret += " - ";
        //}
    }

    
    for (itrt_cat = categories.begin(); itrt_cat != categories.end(); itrt_cat++)//此处取给定的原目录的顺序
    {
        ret += "(" + (*itrt_cat) + " : " + std::to_string(map_cat[*itrt_cat]) + ")";
        if ((itrt_cat + 1) != categories.end())
        {
            ret += " - ";
        }
    }
    return ret;
}



//the best function
/*

*/




//■■■■■■■■■MAIN_TEST
void main_test()
{
    std::vector<std::string> L = { "KDAALI 2","ABART 20", "CDXEFG 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60" ,"KDA 26"};
    std::vector<std::string> M = { "D","S","K","A", "B", "C", "W" };

    for (std::string &s : L)
        std::cout << s << " ";
    std::cout<<std::endl;
    for (std::string &s : M)
        std::cout << s << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << StockList::stockSummary(L,M)<<std::endl;

    system("PAUSE");//等待功能

}
