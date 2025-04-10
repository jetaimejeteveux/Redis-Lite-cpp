#include <gtest/gtest.h>
#include "store/store.hpp"

namespace
{
    class StoreTest : public ::testing::Test
    {
    protected:
        redis_lite::Store store;
    };

    // Test Store::set method
    TEST_F(StoreTest, SetStoresValue)
    {
        // Test Store::set method
        bool result = store.set("test-key", "test-value");

        // Verify the result is true (successful)
        EXPECT_TRUE(result);

        // Get the value back to verify it was stored
        auto value = store.get("test-key");

        // Verify the value is present and matches what we set
        ASSERT_TRUE(value.has_value());
        EXPECT_EQ("test-value", value.value());
    }

    TEST_F(StoreTest, SetUpdatesExistingKey)
    {
        // Set initial value
        store.set("test-key", "initial-value");

        // Update the value
        bool result = store.set("test-key", "updated-value");

        // Verifying the result is true
        EXPECT_TRUE(result);

        // Obtain the value
        auto value = store.get("test-key");

        // Verify if the value is updated
        ASSERT_TRUE(value.has_value());
        EXPECT_EQ("updated-value", value.value());
    }

    TEST_F(StoreTest, GetReturnEmptyForMissingKey)
    {
        auto value = store.get("new-key");
        EXPECT_FALSE(value.has_value());
    }

    TEST_F(StoreTest, DelCanRemoveExistingKey)
    {
        // Arrange
        std::string key = "new-key";
        std::string value = "new-value";
        store.set(key, value);

        // Act
        bool isDeleted = store.del(key);
        auto result = store.get(key);

        // Assert
        EXPECT_TRUE(isDeleted);
        EXPECT_FALSE(result.has_value());
    }

    TEST_F(StoreTest, DelReturnFalseForNonExistingKey)
    {
        // Arrange
        std::string key = "new-key";

        // Act
        bool isDeleted = store.del(key);

        // Assert
        EXPECT_FALSE(isDeleted);
    }
}