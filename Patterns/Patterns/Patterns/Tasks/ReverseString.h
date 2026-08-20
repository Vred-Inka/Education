#pragma once

#include <string>

namespace ReverseString
{
    void Test()
    {
        std::string s = "s123e";
        std::string s1;

        for (int i = s.length() - 1; i>=0; i--)
        {
            s1+=s[i];
        }

        std::cout << s << " " << s1 << std::endl;
    }
    
}
