#include "store/store.hpp"

namespace redis_lite
{

    bool Store::set(const std::string &key, const std::string &value)
    {
        // minimal stub — test will fail
        return false;
    }

    std::optional<std::string> Store::get(const std::string &key) const
    {
        // minimal stub — test will fail
        return std::nullopt;
    }
}