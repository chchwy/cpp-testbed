#include<filesystem>
#include<iostream>
#include<string>
#include<format>

int main() {
    std::string path = "/path/to/directory";
    std::filesystem::path dirPath(path);

    std::cout << dirPath.string() << std::endl;
    return 0;
}