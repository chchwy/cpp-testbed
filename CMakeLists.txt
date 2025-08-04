cmake_minimum_required(VERSION 3.21)
project(CppTestbed VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(testbed
    main.cpp
    doctest.h
    cpp17-filesystem.cpp)

if(MSVC)
    set_target_properties(testbed PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()
