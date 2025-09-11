#include "doctest.h"

TEST_CASE("Test auto type deduction: Value") {

    int x = 42;
    int& rx = x;
    int const cx = x;
    const int& crx = x;
    
    auto v1 = x;   // int
    auto v2 = cx;  // int
    auto v3 = rx;  // int
    auto v4 = crx; // int
    CHECK((std::is_same_v<decltype(v1), int>));
    CHECK((std::is_same_v<decltype(v2), int>));
    CHECK((std::is_same_v<decltype(v3), int>));
    CHECK((std::is_same_v<decltype(v4), int>));
}

TEST_CASE("Test auto type deduction: Pointer") {

    int x = 42;
    const int cx = x;
    int* px = &x;
    const int* cpx = &x;
    int* const cpx2 = &x;
    const int* const cpx3 = &x;

    auto p1 = px;   // int*
    auto p2 = cpx;  // const int*
    auto p3 = cpx2; // int* const
    auto p4 = cpx3; // const int* const
    CHECK((std::is_same_v<decltype(p1), int*>));
    CHECK((std::is_same_v<decltype(p2), const int*>));
    CHECK((std::is_same_v<decltype(p3), int* const>));
    CHECK((std::is_same_v<decltype(p4), const int* const>));
}

TEST_CASE("Test auto type deduction: Reference") {

    int x = 42;
    const int cx = x;
    int& rx = x;
    const int& crx = x;

    auto& r1 = x;   // int&
    auto& r2 = cx;  // const int&
    auto& r3 = rx;  // int&
    auto& r4 = crx; // const int&
    CHECK((std::is_same_v<decltype(r1), int&>));
    CHECK((std::is_same_v<decltype(r2), const int&>));
    CHECK((std::is_same_v<decltype(r3), int&>));
    CHECK((std::is_same_v<decltype(r4), const int&>));
}

TEST_CASE("Test auto type deduction: Const Reference") {

    int x = 42;
    const int cx = x;
    int& rx = x;
    const int& crx = x;

    auto const& r1 = x;   // const int&
    auto const& r2 = cx;  // const int&
    auto const& r3 = rx;  // const int&
    auto const& r4 = crx; // const int&
    CHECK((std::is_same_v<decltype(r1), const int&>));
    CHECK((std::is_same_v<decltype(r2), const int&>));
    CHECK((std::is_same_v<decltype(r3), const int&>));
    CHECK((std::is_same_v<decltype(r4), const int&>));
}