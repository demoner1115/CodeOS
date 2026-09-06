#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void showTree(const fs::path& path, std::string prefix = "")
{
	for (const auto& entry : fs::directory_iterator(path))
	{
		cout << prefix;

		if (entry.is_directory())
			cout << "+-- " << entry.path().filename().string() << "/" << endl;
		else
			cout << "+-- " << entry.path().filename().string() << endl;

		if (entry.is_directory())
		{
			showTree(entry.path(), prefix + "|   ");
		}
	}
}
void location_management(string& nowlocation, const string& wantlocation) {
	fs::path targetPath = fs::path(nowlocation) / wantlocation;

	if (fs::exists(targetPath) && fs::is_directory(targetPath)) {
		nowlocation = targetPath.string();

		cout << "Location changed to: " << nowlocation << endl;
	}
	else {
		cout << "Location not found." << endl;
	}
}

void create_directory(const std::string& dir_name, const std::string& parent_path) {
	fs::path path = fs::path(parent_path) / dir_name;

	if (!fs::exists(path)) {
		fs::create_directory(path);
		std::cout << "Directory created: " << path << std::endl;
	}
	else {
		std::cout << "Directory already exists: " << dir_name << std::endl;
		}
	}
void create_file(const std::string& file_name, const std::string& nowlocation) {
	fs::path path = fs::path(nowlocation) / file_name;

	if (!fs::exists(path)) {
		std::ofstream file(path);
		file.close();
		std::cout << "File created: " << path << std::endl;
	}
	else {
		std::cout << "File already exists: " << path << std::endl;
	}
}