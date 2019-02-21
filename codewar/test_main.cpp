#pragma once
#include<string>
//You can change the following DEFINE to chose different kata which you want to test
//You now have these options£ºTEST_DNA ,TEST_ODD ,TEST_SPDCTRL ,TEST_BOOKSELL,TEST_ONETWO,TEST_LIKET,TEST_TROLLS,TEST_BOUNCINGBALLS

#define TEST_LIKET THIS IS THE CURRENT KATA!

#ifndef TEST_NOW
#define TEST_NOW UNDETERMINED
static std::string UNDETERMINED = "Emmmmm.....";
#endif

#include "chose_kata.h" 


int main()
{
    std::cout << "the current kata is"<<TEST_NOW<<"\n\n";
    
    main_test();
}

