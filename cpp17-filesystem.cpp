#include "doctest.h"
#include <filesystem>

TEST_CASE("Testing filesystem") {
    std::string path = "C:/path/to/directory";
    std::filesystem::path dirPath(path);

    CHECK(dirPath.string() == path);
}
