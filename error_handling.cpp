#include <variant>
#include <vector>
#include <iostream>
#include "doctest.h"

// Helper template for std::visit with multiple lambdas
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

TEST_CASE("Variant Error Handling Succeed") {
    // use std::variant to hold either an std::string or an error code enum
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = "Hello, World!";
    if (std::holds_alternative<std::string>(result)) {
        //std::cout << "Result: " << std::get<std::string>(result) << std::endl;
        CHECK(std::get<std::string>(result) == "Hello, World!");
    } else {
        CHECK(false); // should not reach here
    }
}

TEST_CASE("Variant Error Handling Error") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = ERROR_NOT_FOUND;
    if (std::holds_alternative<std::string>(result)) {
        CHECK(false); // should not reach here
    } else {
        CHECK(std::get<ErrorCode>(result) == ERROR_NOT_FOUND);
    }
}

TEST_CASE("Variant Error Handling with Visitor Success") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = "Hello, Visitor!";

    std::visit(overloaded {
        [](const std::string& value) { CHECK(value == "Hello, Visitor!"); },
        [](ErrorCode error) { CHECK(false); } // should not reach here
    }, result);
}

TEST_CASE("Variant Error Handling with Visitor Error") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = ERROR_INVALID;

    std::visit(overloaded {
        [](const std::string& value) { CHECK(false); }, // should not reach here
        [](ErrorCode error) { CHECK(error == ERROR_INVALID); }
    }, result);
}

TEST_CASE("Variant Error Handling using Index Success") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = "Hello, Visitor!";

    if (result.index() == 0) {
        CHECK(std::get<0>(result) == "Hello, Visitor!");
    } else if (result.index() == 1) {
        CHECK(false); // should not reach here
    }
}

TEST_CASE("Variant Error Handling using Index Error") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = ERROR_INVALID;

    if (result.index() == 0) {
        CHECK(false); // should not reach here
    } else if (result.index() == 1) {
        CHECK(std::get<1>(result) == ERROR_INVALID);
    }
}

TEST_CASE("Variant Error Handling with Exception") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = "Hello, Exception!";

    try {
        std::cout << "Result: " << std::get<std::string>(result) << std::endl;
    } catch (const std::bad_variant_access&) {
        std::cout << "Error code: " << std::get<ErrorCode>(result) << std::endl;
    }
}

TEST_CASE("Variant Error Handling with Alternative Check") {
    using ErrorCode = enum { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };

    std::variant<std::string, ErrorCode> result;
    result = ERROR_NOT_FOUND;

    if (auto value = std::get_if<std::string>(&result)) {
        std::cout << "Result: " << *value << std::endl;
    } else if (auto error = std::get_if<ErrorCode>(&result)) {
        std::cout << "Error code: " << *error << std::endl;
    }
}


enum ErrorCode { SUCCESS, ERROR_NOT_FOUND, ERROR_INVALID };
auto func(int ok) -> std::variant<std::string, ErrorCode> {
    // Some logic here
    if (ok) {
        return "Operation successful";
    } else {
        return ERROR_NOT_FOUND;
    }
}

TEST_CASE("Variant Function Return") {
    auto result = func(1);
    if (std::holds_alternative<std::string>(result)) {
        CHECK(std::get<std::string>(result) == "Operation successful");
    } else {
        CHECK(false); // should not reach here
    }

    result = func(0);
    if (std::holds_alternative<ErrorCode>(result)) {
        CHECK(std::get<ErrorCode>(result) == ERROR_NOT_FOUND);
    } else {
        CHECK(false); // should not reach here
    }
}
