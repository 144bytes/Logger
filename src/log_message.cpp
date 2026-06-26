#include <logger/log_message.hpp>

#include <chrono>
#include <format>
#include <iostream>
#include <syncstream>
#include <thread>

LogMessage::LogMessage(LogLevel level, std::string prefix)
    : level_{level},
      prefix_{std::move(prefix)},
      stream_{}
{
    stream_ << "output: " << GetCurrentTime() << "; ";

    stream_ << ToString(level_) << "; ";

    stream_ << prefix_
            << '('
            << std::this_thread::get_id()
            << "): ";
}

LogMessage::~LogMessage() noexcept
{
    stream_ << '\n';

    std::osyncstream(std::clog) << stream_.str();
}

std::string LogMessage::GetCurrentTime() const noexcept
{
    auto now = std::chrono::system_clock::now();

    return std::format("{:%Y-%m-%d %H:%M:%S}", now);
}
