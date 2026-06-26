# Logger

Simple C++20 logging library based on RAII.

## Features

- RAII-based logging
- Thread-safe output using `std::osyncstream`
- Multiple logging levels
- Custom message prefixes
- Stream-style (`<<`) interface

## Usage

```cpp
Logger logger{"Network"};

logger << "Connected";
logger(ERROR) << "Connection lost";
```
