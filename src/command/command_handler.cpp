#include "command/command_handler.hpp"
#include <sstream>
#include <algorithm>

std::vector<std::string> CommandHandler::tokenize(const std::string &command)
{
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    std::string token;

    while (iss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}

std::string CommandHandler::handleCommand(const std::string &command)
{
    return "ERROR: Not Yet Implemented";
}