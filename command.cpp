#include "command.h"
#include <iostream>
#include <vector>
#include <string>
#include "users.h"
#include "file.h"

using namespace std;

vector<Command> commands;

void runCommand(
    const vector<string>& commandargs,
    int& nowstatus,
    string& nowname,
    string& nowlocation
) {
    // 명령어가 비어있으면 종료
    if (commandargs.empty()) {
        return;
    }

    string command = commandargs[0];

    // ========================================
    // 로그인하지 않은 상태
    // ========================================
    if (nowstatus == 0) {

        // login
        if (command == "login") {
			Log_in(nowstatus, nowname, nowlocation);
        }

        // register
        else if (command == "register") {
            Register(nowstatus, nowname, nowlocation);
        }

        // exit
        else if (command == "exit") {
            nowstatus = -1;
            return;
        }

        // 로그인하지 않은 상태에서 다른 명령어
        else {
            cout << "Please login or register first." << endl;
        }

        return;
    }


    // ========================================
    // 로그인한 상태
    // ========================================
    if (nowstatus == 1) {

        // logout
        if (command == "logout") {

            nowstatus = 0;
            nowname = "";
            nowlocation = "main";

            cout << "Logged out successfully." << endl;
        }

        // ls
        else if (command == "ls") {

            // TODO: 현재 디렉토리 내용 출력
			showTree(nowlocation);
        }

        // cd
        else if (command == "cd") {

            if (commandargs.size() < 2) {
                cout << "Usage: cd <directory>" << endl;
                return;
            }

            const string& directory = commandargs[1];

            location_management(nowlocation, directory);
        }

        // pwd
        else if (command == "pwd") {

            cout << nowlocation << endl;
        }

        // mkdir
        else if (command == "mkdir") {

            if (commandargs.size() < 2) {
                cout << "Usage: mkdir <directory>" << endl;
                return;
            }

            const string& directory = commandargs[1];

            create_directory(directory, nowlocation);
        }

        // touch
        else if (command == "touch") {

            if (commandargs.size() < 2) {
                cout << "Usage: touch <filename>" << endl;
                return;
            }

            const string& filename = commandargs[1];

            create_file(filename, nowlocation);
        }

        // rm
        else if (command == "rm") {

            if (commandargs.size() < 2) {
                cout << "Usage: rm <filename>" << endl;
                return;
            }

            const string& filename = commandargs[1];

            cout << "Not Yet" << endl;
        }

        // rmdir
        else if (command == "rmdir") {

            if (commandargs.size() < 2) {
                cout << "Usage: rmdir <directory>" << endl;
                return;
            }

            const string& directory = commandargs[1];

            cout << "Not Yet" << endl;
        }

        // help
        else if (command == "help") {

            cout << "Available commands:" << endl;
            cout << "login <username> <password> - Log in to the system" << endl;
            cout << "register - Register a new user" << endl;
            cout << "logout - Log out" << endl;
            cout << "ls - List directory contents" << endl;
            cout << "cd <directory> - Change directory" << endl;
            cout << "pwd - Show current directory" << endl;
            cout << "mkdir <directory> - Create directory" << endl;
            cout << "touch <filename> - Create file" << endl;
            cout << "rm <filename> - Remove file" << endl;
            cout << "rmdir <directory> - Remove directory" << endl;
            cout << "help - Show this help message" << endl;
            cout << "exit - Exit CodeOS" << endl;
        }

        // 존재하지 않는 명령어
        else {
            cout << "Unknown command: " << command << endl;
        }
    }
}