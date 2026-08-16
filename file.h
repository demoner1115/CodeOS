#pragma once

#include <string>
#include <filesystem>

void location_management(std::string wantlocation, std::string& nowlocation);
void showTree(const std::filesystem::path& path, std::string prefix = "");
void create_directory(const std::string& dir_name);
void create_file(const std::string& file_name);