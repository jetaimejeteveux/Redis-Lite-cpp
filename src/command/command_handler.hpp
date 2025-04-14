// include/net/command_handler.hpp
#ifndef REDIS_LITE_COMMAND_HANDLER_HPP
#define REDIS_LITE_COMMAND_HANDLER_HPP

#include <string>
#include <vector>
#include "store/store.hpp"

class CommandHandler
{
public:
    explicit CommandHandler(redis_lite::Store &store) : store_(store) {}

    // Handle a command and return response
    std::string handleCommand(const std::string &command);

private:
    redis_lite::Store &store_;

    // Helper to split command into tokens
    std::vector<std::string> tokenize(const std::string &command);

    // Command handlers
    std::string handleSet(const std::vector<std::string> &tokens);
    std::string handleGet(const std::vector<std::string> &tokens);
    std::string handleDel(const std::vector<std::string> &tokens);
};

#endif