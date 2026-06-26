#ifndef LOG_MESSAGE
#define LOG_MESSAGE

#include "types.hpp"

#include <sstream>

class LogMessage
{
public:
    LogMessage(LogMessage&&) = default;
    LogMessage& operator=(LogMessage&&) = default;

    LogMessage(const LogMessage&) = delete;
    LogMessage& operator=(const LogMessage&) = delete;

    LogMessage(LogLevel level = INFO, std::string prefix = "");
    ~LogMessage() noexcept;

    template<typename MessageType>
    LogMessage& operator<<(const MessageType& message) noexcept;

    std::string GetCurrentTime() const noexcept;

private:
    LogLevel level_;
    std::string prefix_;
    std::ostringstream stream_;
};

template<typename MessageType>
LogMessage& LogMessage::operator<<(const MessageType& message) noexcept
{
    stream_ << message;

    return *this;
}

#endif // LOG_MESSAGE
