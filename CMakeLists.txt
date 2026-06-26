cmake_minimum_required(VERSION 3.20)

project(Logger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(logger STATIC
    src/logger.cpp
    src/log_message.cpp
    src/types.cpp
)

target_include_directories(logger
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(logger PRIVATE -Wall -Wextra -Wpedantic)
