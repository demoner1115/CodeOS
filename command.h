#pragma once

#include <string>
#include <vector>
#include <functional>

struct Command {
	std::string name;
	std::function<void(const std::vector<std::string>&)> execute;
};
void runCommand(
	const std::vector<std::string>& commandargs,
	int& nowstatus,
	std::string& nowname,
	std::string& nowlocation
);