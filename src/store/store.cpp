#include "store/store.hpp"

namespace redis_lite
{

    bool Store::set(const std::string &key, const std::string &value)
    {
        std::lock_guard lock(mutex_);
        data_[key] = value;
        return true;
    }

    std::optional<std::string> Store::get(const std::string &key) const
    {
        std::lock_guard lock(mutex_);
        if (auto it = data_.find(key); it != data_.end())
        {
            return it->second;
        }
        return std::nullopt;
    }

    bool Store::del(const std::string &key)
    {
        return false;
    }

}