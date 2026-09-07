#pragma once

#include <string>
class Parser
{
public:
    static int ParseInt(const std::string& str);

    static int ReadPortFromConfig(const std::string& str);
};
