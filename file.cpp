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
void location_management(string wantlocation, string& nowlocation) {
	fs::path targetPath = fs::path(nowlocation) / wantlocation;

	if (fs::exists(targetPath)) {
		cout << "Location changed to: " << wantlocation << endl;
		nowlocation = targetPath.string();
	}
	else {
		cout << "Location not found." << endl;
	}
}

void create_directory(const std::string& dir_name) {
	if (!fs::exists(dir_name)) {
		fs::create_directory(dir_name);
		std::cout << "Directory created: " << dir_name << std::endl;
	}
	else {
		std::cout << "Directory already exists: " << dir_name << std::endl;
	}
}
void create_file(const std::string& file_name) {
	if (!fs::exists(file_name)) {
		std::ofstream file(file_name);
		file.close();
		std::cout << "File created: " << file_name << std::endl;
	}
	else {
		std::cout << "File already exists: " << file_name << std::endl;
	}
}