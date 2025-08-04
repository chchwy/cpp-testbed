cmake_minimum_required(VERSION 3.21)
project(CppTestbed VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(kirara main.cpp)

if (MSVC)
    target_compile_definitions(kirara PRIVATE
        UNICODE
        _UNICODE
    )
endif()
