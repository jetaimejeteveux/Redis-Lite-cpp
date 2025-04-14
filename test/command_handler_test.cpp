#include "command/command_handler.hpp"
#include "gtest/gtest.h"
#include "store/store.hpp" // Include the header for your Store class

class CommandHandlerTest : public ::testing::Test
{
protected:
    redis_lite::Store store_;
    CommandHandler handler{store_};

    CommandHandlerTest() : store_(), handler(store_) // Initialize store and handler in constructor
    {
    }

    ~CommandHandlerTest() override = default;
};

TEST_F(CommandHandlerTest, ParseSetCommand)
{
    // Example test case using the `handler`
    std::string result = handler.handleCommand("SET test-key test-value");
    EXPECT_EQ(result, "OK");
    EXPECT_EQ(store_.get("test-key"), "test-value");
}
