#ifndef LOGGER
#define LOGGER

#include "log_message.hpp"

class Logger
{
public:
    explicit Logger(std::string prefix = "");

    LogMessage operator()() const noexcept;
    LogMessage operator()(LogLevel level) const noexcept;

    template<typename MessageType>
    LogMessage operator<<(const MessageType& message) const noexcept;

private:
    std::string prefix_;
};

template<typename MessageType>
LogMessage Logger::operator<<(const MessageType& message) const noexcept
{
    auto msg = LogMessage{INFO, prefix_};

    msg << message;

    return msg;
}

#endif // LOGGER
