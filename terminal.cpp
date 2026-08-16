#include <fstream>
#include <string>
#include <iostream>
#include "users.h"
#include <filesystem>
#include "file.h"
#include "terminal.h"


using namespace std;
namespace fs = std::filesystem;

void terminal(std::string& nowlocation, int& nowstatus, std::string& nowname);

void terminal(std::string& nowlocation, int& nowstatus, std::string& nowname) {
	cout << "Welcome to the terminal!" << endl;
	while (true) {
		std::string command;
		cout << nowlocation << "> ";
		cin >> command;
		if (nowstatus == 0) {
			if (command == "login") {
				Log_in(nowstatus, nowname, nowlocation);
			}
			else if (command == "register") {
				Register(nowstatus, nowname, nowlocation);
			}
			else if (command == "exit") {
				break;
			}
			else if (command == "help") {
				cout << "Available commands: login, register, exit, help, logout" << endl;
			}
			else if (command == "logout") {
				cout << "You are not logged in!" << endl;
			}
			else {
				cout << "error" << endl;
			}
		}
		else if (nowstatus == 1) {
			if (command == "login") {
				Log_in(nowstatus, nowname, nowlocation);
			}
			else if (command == "register") {
				Register(nowstatus, nowname, nowlocation);
			}
			else if (command == "exit") {
				break;
			}
			else if (command == "help") {
				cout << "Available commands: login, register, exit, help, logout, location, show, mkdir, touch" << endl;
			}
			else if (command == "logout") {
				nowstatus = 0;
				nowname = "";
				cout << "Logged out successfully!" << endl;
			}
			else if (command == "location") {
				std::string wantlocation;
				cin >> wantlocation;
				location_management(wantlocation, nowlocation);
			}
			else if (command == "show") {
				showTree(nowlocation);
			}
			else if (command == "mkdir") {
				std::string dir_name;
				cin >> dir_name;
				create_directory(nowlocation + "/" + dir_name);
			}
			else if (command == "touch") {
				std::string file_name;
				cin >> file_name;
				create_file(nowlocation + "/" + file_name);
			}
			else {
				cout << "error" << endl;
			}
		}
		else {
			cout << "error" << endl;
		}
	}
}