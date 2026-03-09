#include "Assets.h"
#include <iostream>
#include <filesystem>
#include <string>

std::map<std::string, Object*> Assets::assets;

namespace fs = std::filesystem;

void Assets::CheckFolder(std::string path)
{
    // Iterate through files (non-recursive)
    //std::cout << "\nFiles in folder:\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.status())) {
            //ConvertToAsset();
            std::cout << "File: " << entry.path().filename().string() << '\n';
        }
        else if (fs::is_directory(entry.status())) {
            CheckFolder(entry.path().string());
            //std::cout << "Directory: " << entry.path().filename().string() << '\n';
        }
    }

    // Optional: Recursive iteration
    std::cout << "\nRecursive listing:\n";
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        std::cout << entry.path().string() << '\n';
    }
}

void Assets::Load(std::string root)
{
    std::vector<std::string> paths;
	paths.push_back(root + "images");

    for (auto& path : paths) {
        try {
            // Check if the path exists and is a directory
            if (!fs::exists(path)) {
                std::cerr << "Error: Path does not exist.\n";
                continue;
            }
            if (!fs::is_directory(path)) {
                std::cerr << "Error: Path is not a directory.\n";
                continue;
            }

            CheckFolder(path);

        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "Filesystem error: " << e.what() << '\n';
            continue;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
            continue;
        }
    }
}


/*template<class Object>
Object* Assets::Get(std::string path)
{
    Object* object = assets.at(path);
    if (object) {
        return object
    }
    return nullptr;
}
*/