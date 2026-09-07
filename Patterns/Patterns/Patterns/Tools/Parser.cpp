#include "Parser.h"

#include <stdexcept>
#include <string>

int Parser::ParseInt(const std::string& str)
{
    int result = 0;
    for (char c : str)
    {
        if (c < '0' || c > '9')
        {
            throw std::runtime_error("invalid integer");
        }
        result = result * 10 + (c - '0');
    }
    return result;
}

int Parser::ReadPortFromConfig(const std::string& str)
{
    int port = ParseInt(str);
    if (port <= 0 || port >= 65536)
    {
        throw std::runtime_error("invalid port");
    }

    return port;
}

