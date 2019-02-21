#include "stdafx.h"
#include<iostream>
#include "CppUnitTest.h"
#include <vector>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace codewar_byCy
{
    TEST_CLASS(UnitTest1)
    {
    public:

        const string yes = "YES";
        const string no = "NO";
        static vector<int> v[2];

        TEST_METHOD(CurtCode)
        {
            v[0] = { 25, 25, 50, 50 };
            v[1] = { 25, 100 };
            Assert::AreEqual(CurtCode(v[0]), yes);
            Assert::AreEqual(CurtCode(v[1]), no);
        }

        std::string CurtCode(const vector<int> peopleInLine)
        {
            int a = 0, b = 0, i = -1;
            while (++i<peopleInLine.size())
            {
                if (peopleInLine[i] == 25)
                {
                    a++;
                }
                else if (peopleInLine[i] == 50 && a > 0)
                {
                    a--; b++;
                }
                else if (peopleInLine[i] == 100 && a > 0 && b > 0)
                {
                    a--; b--;
                }
                else if (peopleInLine[i] == 100 && a > 2)
                {
                    a -= 3;
                }
                else return "NO";
            }
            return "YES";
        }

        //A Clever Code
        std::string tickets(const std::vector<int> peopleInLine)
        {
            int a = 0, b = 0;
            for (auto v : peopleInLine)
            {
                if (v == 25) a++;
                if (v == 50)
                {
                    b++; a--;
                }
                if (v == 100)
                {
                    a--; b > 0 ? b-- : a -= 2;
                }
                if (a < 0 || b < 0) return "NO";
            }
            return "YES";
        }

        TEST_METHOD(IfElseCode)
        {
            Assert::AreEqual(IfElseCode({ 25, 25, 50, 50 }), yes);
            Assert::AreEqual(IfElseCode({ 25, 100 }), no);
        }

        TEST_METHOD(SwitchCaseCode)
        {
            Assert::AreEqual(SwitchCaseCode({ 25, 25, 50, 50 }), yes);
            Assert::AreEqual(SwitchCaseCode({ 25, 100 }), no);
        }

        std::string IfElseCode(const vector<int> peopleInLine)
        {
            int i25 = 0;
            int i50 = 0;
            for (int i = 0; i < peopleInLine.size(); i++)
            {
                if (25 == peopleInLine[i]) i25 += 25;
                else if (50 == peopleInLine[i])
                {
                    if (i25 == 0)return"NO";
                    i25 -= 25;
                    i50 += 50;
                }
                else
                {
                    if (i25 < 25 || i25 + i50 < 75) return"NO";
                    i25 -= 25;
                    if (i50 >= 50)i50 -= 50;
                    else if (i25 >= 50)i25 -= 50;
                    else return "NO";
                }
            }
            return "YES";
        }

        std::string SwitchCaseCode(const vector<int> peopleInLine)
        {
            int i25 = 0;
            int i50 = 0;
            for (int i = 0; i < peopleInLine.size(); i++)
            {
                switch (peopleInLine[i])
                {
                case 25:i25 += 25; break;
                case 50:
                    if (i25 == 0)return"NO";
                    i25 -= 25;
                    i50 += 50;
                    break;
                default:
                    if (i25 >= 25 && i50 >= 50)
                    {
                        i25 -= 25;
                        i50 -= 50;
                    }
                    else if (i25 >= 75)
                    {
                        i25 -= 75;
                    }
                    else
                    {
                        return "NO";
                    }
                    break;
                }
            }
            return "YES";
        }

    };

}
