#ifndef REDIS_LITE_STORE_HPP
#define REDIS_LITE_STORE_HPP

#include <string>
#include <unordered_map>
#include <optional>
#include <mutex>

namespace redis_lite
{
    class Store
    {
    public:
        Store() = default;
        ~Store() = default;

        // Delete copy and move constructors/assignment operators
        Store(const Store &) = delete;
        Store &operator=(const Store &) = delete;
        Store(Store &&) = delete;
        Store &operator=(Store &&) = delete;

        // Core operations
        bool set(const std::string &key, const std::string &value);
        std::optional<std::string> get(const std::string &key) const;
        bool del(const std::string &key);

    private:
        // In-memory storage
        std::unordered_map<std::string, std::string> data_;

        // Mutex for thread safety
        mutable std::mutex mutex_;
    };
}

#endif