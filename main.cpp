#include<filesystem>
#include<iostream>
#include<string>
#include<format>

int main() {
    std::string path = "C:/path/to/directory";
    std::filesystem::path dirPath(path);

    std::cout << "Out:" << dirPath.string() << std::endl;
    return 0;
}