#include <iostream>
#include <bitset>
#include <map>
#include <tuple>
#include <string>
#include "doctest.h"

TEST_CASE("C++14 Binary Literals") {
    CHECK(0b0 == 0);
    CHECK(0b1 == 1);
    CHECK(0b10 == 2);
    CHECK(0b11 == 3);
    CHECK(0b100 == 4);
    CHECK(0b1010 == 10);
    CHECK(0b1111 == 15);
    CHECK(0b10000000 == 128);
    CHECK(0b11111111 == 255);
    CHECK(0b101010101010 == 0xAAA);
    CHECK(0b1111111111111111 == 0xFFFF);
    CHECK(0b0000100000000000 == (1 << 11));
    CHECK(0b011101110111 == 0x777);
    std::bitset<8> bits(0b10000000);
    CHECK(bits.to_ulong() == 128);
}

TEST_CASE ("C++14 Generic Lambdas") {
    auto add = [](auto a, auto b) {
        return a + b;
    };

    CHECK(add(2, 3) == 5);
    CHECK(add(2.5f, 3.5) == 6.0);

    std::string str1 = "Hello, ";
    std::string str2 = "Matt!";
    CHECK(add(str1, str2) == "Hello, Matt!");
}

TEST_CASE("C++14 Get to know Variable Types") {
    int x = 42;
    auto t = std::make_tuple(x);
    //decltype(t)::foo = 1; // Intentionally use non-existing member named foo
    // To force compiler to print an error with the actual type of t
}

TEST_CASE("C++14 Structured Bindings") {

    // Structured bindings allow unpacking tuples, pairs, and arrays
    auto [a, b, c] = std::make_tuple(1, 2.5, "Hello");
    CHECK(a == 1);
    CHECK(b == 2.5);
    CHECK(std::string(c) == "Hello");

    auto [x, y] = std::pair<int, double>(3, 1000.5);
    CHECK(x == 3);
    CHECK(y == 1000.5);

    // Structured bindings with arrays
    int arr[] = {1, 2, 3};
    auto [first, second, third] = arr;
    CHECK(first == 1);
    CHECK(second == 2);
    CHECK(third == 3);

    // Structured bindings with std::map
    std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}, {"three", 3}};
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
        if (key == "one") {
            CHECK(value == 1);
        } else if (key == "two") {
            CHECK(value == 2);
        } else if (key == "three") {
            CHECK(value == 3);
        }
    }
}
