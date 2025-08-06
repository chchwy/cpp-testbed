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

TEST_CASE("C++14 Get to know Variable Types") {
    int x = 42;
    auto t = std::make_tuple(x);
    //decltype(t)::foo = 1; // Intentionally use non-existing member named foo
    // To force compiler to print an error with the actual type of t
}
