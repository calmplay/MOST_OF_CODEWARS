#pragma once
#include<iostream>
# include <string>

//you can choose to test the best function insteed of you own function by annotate the following define 
//#define MY_FUNCTION

#ifndef MY_FUNCTION
#define BEST_FUNCTION
#endif

//# include <malloc.h>

//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
//KATA:Disemvowel Trolls
/*-------------------------------------------------------------
Trolls are attacking your comment section!

A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.

Your task is to write a function that takes a string and return a new string with all vowels removed.

For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".

Note: for this kata y isn't considered a vowel.



Describe(Sample_tests)
{
It(Tests)
{
Assert::That(disemvowel("This website is for losers LOL!"),
Equals("Ths wbst s fr lsrs LL!"));
}
};

*/



#ifdef MY_FUNCTION

std::string disemvowel(std::string str)
{
    std::string vowels = "AEIOUaeiou";
    std::string p = str;
    std::string::iterator p_upd = p.begin();
    std::string::iterator p_mov = p.begin();

    std::string::iterator i_v = vowels.begin();

    while (p_mov!=p.end())
    {
        if (*p_mov == *i_v)
        {
            *p_mov++;
            i_v = vowels.begin();
        }
        else if (++i_v == vowels.end())
        {
            *p_upd = *p_mov;
            p_upd++ ;
            p_mov++ ;
            i_v = vowels.begin();
        }
    }

    return std::string(p.begin(),p_upd);
}

#endif




#ifdef BEST_FUNCTION


# include <regex>

std::string disemvowel(std::string str)
{
std::regex vowels("[aeiouAEIOU]");
return std::regex_replace(str, vowels, "");
}

#endif



//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öMAIN_TEST
void main_test()
{

    std::string str="This website is for losers LOL!";
    std::cout << str<<std::endl;
    std::cout << disemvowel(str)<<std::endl;
    system("PAUSE");//µÈ´ý¹¦ÄÜ

}
