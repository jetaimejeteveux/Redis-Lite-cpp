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
    auto tokens = tokenize(command);

    if (tokens.empty())
    {
        return "ERROR: Empty command";
    }

    // Convert command to uppercase for case-insensitive comparison
    std::string cmd = tokens[0];
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);

    if (cmd == "SET")
    {
        return handleSet(tokens);
    }

    return "ERROR: Unknown command";
}

std::string CommandHandler::handleSet(const std::vector<std::string> &tokens)
{
    if (tokens.size() < 3)
    {
        return "ERROR: Syntax error. Usage: SET key value";
    }

    const std::string &key = tokens[1];
    const std::string &value = tokens[2];

    if (store_.set(key, value))
    {
        return "OK";
    }
    else
    {
        return "ERROR: Failed to set value";
    }
}