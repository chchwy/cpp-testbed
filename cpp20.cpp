#include <string>
#include "doctest.h"


auto add(auto a, auto b) {
    return a + b;
}

template<typename T1, typename T2>
auto add2(T1 x, T2 y) -> decltype(x + y) {
    return x + y;
}

TEST_CASE("C++20 Auto Template Shorthand") {

    // New C++20 auto template shorthand
    // This allows us to use 'auto' in function parameters
    // and return types, simplifying the syntax.
    CHECK(add(2, 3) == 5);
    CHECK(add(2.5f, 3.5) == 6.0);

    std::string str1 = "Hello, ";
    std::string str2 = "Matt!";
    CHECK(add(str1, str2) == "Hello, Matt!");

    // Traditional function template
    CHECK(add2(2, 3) == 5);
    CHECK(add2(2.5f, 3.5) == 6.0);

    std::string str3 = "Hello, ";
    std::string str4 = "Matt!";
    CHECK(add2(str3, str4) == "Hello, Matt!");
}