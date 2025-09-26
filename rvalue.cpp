#include <vector>
#include "doctest.h"


std::vector<int> getVector() {
    return {1, 2, 3, 4, 5};
}

TEST_CASE("C++11 Basic Test") {
    
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int>&& v2 = getVector(); // rvalue reference

    auto&& v3 = std::vector<int>{6, 7, 8, 9, 10}; // rvalue reference to temporary
    CHECK(v1.size() == 5);
    CHECK(v2.size() == 5);
    CHECK(v3.size() == 5);
}