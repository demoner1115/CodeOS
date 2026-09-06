#include <iostream>
#include <string>
#include <vector>
#include "parser.h"
#include "command.h"

using namespace std;

void shell()
{
    vector<string> commandargs;

    int nowstatus = 0;
    string nowname = "";
    string nowlocation = "main";

    while (true) {
        string input;

        cout << "> ";
        getline(cin, input);

        parseCommand(input, commandargs, nowstatus, nowname, nowlocation);

        runCommand(
            commandargs,
            nowstatus,
            nowname,
            nowlocation
        );

        if (nowstatus == -1)
            break;
    }
}