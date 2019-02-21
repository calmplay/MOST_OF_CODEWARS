#pragma once
#include<iostream>
#include<string>
#include <algorithm>  
#include<set>

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
//KATA5:Two to One
/*-------------------------------------------------------------
Take 2 strings s1 and s2 including only letters from ato z. Return a new sorted string, the longest possible, containing distinct letters,

each taken only once - coming from s1 or s2. #Examples: ``` a = "xyaabbbccccdefww" b = "xxxxyyyyabklmopq" longest(a, b) -> "abcdefklmopqwxy"
a = "abcdefghijklmnopqrstuvwxyz" longest(a, a) -> "abcdefghijklmnopqrstuvwxyz" ```


dotest("aretheyhere", "yestheyarehere", "aehrsty");
dotest("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");
*/


//my function

class TwoToOne
{
public:
static std::string longest(const std::string &s1, const std::string &s2);
};

//std::string TwoToOne::longest(const std::string &s1, const std::string &s2)
//{
//    std::string total = s1+s2, ret = "";
//    char temp = ' ';
//    std::sort(total.begin(), total.end());
//
//    
//
//    for (char &c : total)
//    {
//        if (c != temp)
//        {
//            ret += c;
//            temp = c;
//        }          
//    }
//
//    return ret;
//}



//the best function

std::string TwoToOne::longest(const std::string& s1, const std::string& s2)
{
    //std::set<char> chars;
    //chars.insert('y');
    // chars.insert('s'); 
    // chars.insert('a');
    // chars.insert('b');         //find that: all the action of insert by a set will be taken sorted!!   by the easy test
    std::set<char> chars(s1.begin(), s1.end());        //to see if the members are sorted in set in the moment after this！
    for (char c : s2)
        chars.insert(c);                               //to see if the members are sorted in set in the moment after this！
    return std::string(chars.begin(), chars.end());
}

//A:Can someone please explain me how this comes out sorted? ^^
//B:It's a property of set container.  //★★★set的特性
//  Here http://www.cplusplus.com/reference/set/set/ you could see that, internally, the elements in a set are always sorted.






//■■■■■■■■■MAIN_TEST
void main_test()
{
    std::string s1 = "zyudglsdigssgasgg";
    std::string s2 = "xygasgpqjliqmba";

    std::cout<<s1<<std::endl<<s2<<std::endl;

    std::cout << TwoToOne::longest(s1,s2)<<std::endl;

    system("PAUSE");//等待功能

}
