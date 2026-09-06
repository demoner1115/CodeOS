#include <iostream>
#include <string>
#include "parser.h"
#include <sstream>
#include <vector>
#include "command.h"

using namespace std;

void parseCommand(
    string& command,
    vector<string>& commandargs,
    int& nowstatus,
    string& nowname,
    string& nowlocation
) {
    string word;
    stringstream ss(command);

    commandargs.clear();

    while (ss >> word) {
        commandargs.push_back(word);
    }
}