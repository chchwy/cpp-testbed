#include <string>
#include <iostream>
#include "doctest.h"

TEST_CASE("C++17 std::string_view concatenation and comparison") {
    std::string_view sv1 = "Hello, ";
    std::string_view sv2 = "World!";
    
    // Concatenate using std::string
    std::string concatenated = std::string(sv1).append(sv2);
    CHECK(concatenated == "Hello, World!");
    CHECK(std::string("Hello, ").append(sv2) == "Hello, World!");
}