#include "doctest.h"

auto add(auto a, auto b) {
    return a + b;
}

TEST_CASE("Auto Function Template") {
    CHECK(add(2, 3) == 5);
    CHECK(add(2.5f, 3.5) == 6.0);

    std::string str1 = "Hello, ";
    std::string str2 = "Matt!";
    CHECK(add(str1, str2) == "Hello, Matt!");
}