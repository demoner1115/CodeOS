#pragma once

#include <string>
#include <filesystem>

void location_management(std::string& nowlocation, const std::string& wantedlocation);
void showTree(const std::filesystem::path& path, std::string prefix = "");
void create_directory(const std::string& dir_name, const std::string&nowlocation);
void create_file(const std::string& file_name, const std::string& nowlocation);