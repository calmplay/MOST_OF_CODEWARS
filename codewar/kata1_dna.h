#pragma once
#include<iostream>
#include<string>

//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö
//KATA1:Complementary DNA
/*-------------------------------------------------------------
In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You have function with one side of the DNA (string, except for Haskell); you need to get the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

FOR EXAMPLE:
DNA_strand ("ATTGC") # return "TAACG"

DNA_strand ("GTAT") # return "CATA"
*/


//my function
//std::string DNAStrand(const std::string& dna)
//{
//    std::string dna_f = dna;
//    for (auto &c : dna_f)
//    {
//        switch (c)
//        {
//        case 'C': c = 'G'; break;
//        case 'G': c = 'C'; break;
//        case 'A': c = 'T'; break;
//        case 'T': c = 'A'; break;
//        }
//    }
//    return dna_f;
//}

//the best function
#include <map>

const std::map<char, char> mapping =
{
    { 'A', 'T' },
    { 'T', 'A' },
    { 'C', 'G' },
    { 'G', 'C' },
};

std::string DNAStrand(const std::string& dna)
{
    std::string DNA = dna;
    for (char& c : DNA)
    {
        c = mapping.at(c);
    }
    return DNA;
}

//¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡ö¡öMAIN_TEST
void main_test()
{
    std::string dna_str = "AGCGACTGATCG";
    std::cout <<"before:"<< dna_str << std::endl;


    dna_str = DNAStrand(dna_str);
    int a = 1;
    std::cout <<"after :"<< dna_str << std::endl;

    system("PAUSE");//µÈ´ý¹¦ÄÜ

}
