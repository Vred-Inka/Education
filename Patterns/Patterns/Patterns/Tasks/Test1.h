#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class Test1
{
public:
    static void RevertString()
    {
        std::string s = "s123e";
        std::string s1;

        for (int i = s.length() - 1; i>=0; i--)
        {
            s1+=s[i];
        }

        std::cout << s << " " << s1 << std::endl;
    }
};
