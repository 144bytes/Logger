#include <logger/types.hpp>

std::string ToString(const LogLevel level)
{
    switch (level)
    {
        case INFO:
            return "INFO";
        case DEBUG:
            return "DEBUG";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "INFO";
    }
}
