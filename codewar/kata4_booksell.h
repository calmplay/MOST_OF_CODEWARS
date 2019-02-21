#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<map>

//����������������������������������������������������������������
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
static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);//art means ��Ʒ here
};


std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories)
{    
    //�����ǸĶ�����߼�:��Ϊ���Ҫ�󷵻ص�stringҪ����˳�����,�ʸ��Ʋ�����ԭcategories����ĸ˳��
    //Ȼ������û��������󣬴ӳ���İ�ȫ����ҲӦ����ô����
    std::vector<std::string> lstOfArt_2 = lstOfArt;
    std::vector<std::string> categories_2 = categories;
    std::sort(lstOfArt_2.begin(), lstOfArt_2.end());
    std::sort(categories_2.begin(), categories_2.end());

    //map������ģ�����޷�����������ԭcategories_2����ĸ˳��
    std::map<std::string, int> map_cat;//���ڽ�{"A","C","D"...}ת��Ϊ{("A",20),("C",23),("D",38)...}

    std::vector<std::string>::iterator itrt_artlst = lstOfArt_2.begin();//���ڱ�����������Ʒ�嵥
    std::vector<std::string>::iterator itrt_cat = categories_2.begin();//���ڱ�������������ĸĿ¼�嵥

    //std::regex reg1("\\d+");//\\����ת�� �ʴ�ʽ�ȼ���ʽ�ӣ�\d+
    std::regex reg1("\\d+");
    std::smatch r1;

    std::string ret = "";

    for (; itrt_cat != categories_2.end(); itrt_cat++)
    {
        map_cat[*itrt_cat] = 0;
        //ret += "(" + (*itrt_cat) + " : ";//��Ϊ������ض����󼰸Ķ������ڴ�ѭ����ƴ���ַ�������Ϊ˳���ǲ��Ե�


        //for (; itrt_artlst != lstOfArt_2.end(); itrt_artlst++)//�٢�����Ϊ�µĸĶ����ǳ���Ҫ����
        for (; itrt_artlst != lstOfArt_2.end(); )//���   
        {
            if ((*itrt_artlst).substr(0, 1) == (*itrt_cat))
            {
                std::regex_search(*itrt_artlst, r1, reg1);
                map_cat[*itrt_cat] += atoi(r1.str().c_str());//stringתint
                itrt_artlst++;//���      
            }
            else
            {
                break;
            }
        }

        //��Ϊ������ض����󼰸Ķ������ڴ�ѭ����ƴ���ַ�������Ϊ˳���ǲ��Ե�
        //ret += std::to_string(map_cat[*itrt_cat]) + ")";
        //if ((itrt_cat+1) != categories_2.end())
        //{
        //    ret += " - ";
        //}
    }

    
    for (itrt_cat = categories.begin(); itrt_cat != categories.end(); itrt_cat++)//�˴�ȡ������ԭĿ¼��˳��
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




//������������������MAIN_TEST
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

    system("PAUSE");//�ȴ�����

}
