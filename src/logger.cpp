#include <logger/logger.hpp>

Logger::Logger(std::string prefix)
    : prefix_{std::move(prefix)}
{
}

LogMessage Logger::operator()() const noexcept
{
    return LogMessage{INFO, prefix_};
}

LogMessage Logger::operator()(LogLevel level) const noexcept
{
    return LogMessage{level, prefix_};
}
