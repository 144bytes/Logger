#ifndef TYPES
#define TYPES

#include <string>

enum LogLevel
{
    INFO,
    DEBUG,
    WARNING,
    ERROR
};

std::string ToString(const LogLevel level);

#endif // TYPES
