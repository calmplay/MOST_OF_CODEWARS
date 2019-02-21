#pragma once
#include<iostream>
#include<vector>

//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
//KATA6:Who likes it?
/*-------------------------------------------------------------
You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.

Implement a function likes :: [String] -> String, which must take in input array, containing the names of people who like an item. It must return the display text as shown in the examples:



likes {} // must be "no one likes this"
likes {"Peter"} // must be "Peter likes this"
likes {"Jacob", "Alex"} // must be "Jacob and Alex like this"
likes {"Max", "John", "Mark"} // must be "Max, John and Mark like this"
likes {"Alex", "Jacob", "Mark", "Max"} // must be "Alex, Jacob and 2 others like this"



For 4 or more names, the number in and 2 others simply increases.




Assert::That(likes({}), Equals("no one likes this"));
Assert::That(likes({"Peter"}), Equals("Peter likes this"));
Assert::That(likes({"Jacob", "Alex"}), Equals("Jacob and Alex like this"));
Assert::That(likes({"Max", "John", "Mark"}), Equals("Max, John and Mark like this"));
Assert::That(likes({"Alex", "Jacob", "Mark", "Max"}), Equals("Alex, Jacob and 2 others like this"));
*/


//my function

std::string likes(const std::vector<std::string> &names)
{
    switch (names.size())
    {
        case 0:return "no one likes this";
        case 1:return (names[0]) + " likes this";
        case 2:return names[0] + " and " + names[1] + " like this";
        case 3:return names[0] + ", " + names[1] + " and "+ names[2] +" like this";
        default:return names[0] + ", " + names[1] + " and " + std::to_string(names.size()-2) + " others like this";
    }
    return ""; // Do your magic!

}


//the best function
/*

*/




//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öMAIN_TEST
void main_test()
{
    std::vector<std::string> L = { "Alex", "Jacob", "Mark", "Max" };
    std::cout << likes(L)<<std::endl;
    system("PAUSE");//µÈ´ý¹¦ÄÜ

}
