#include <iostream>
#include "users.h"
#include "terminal.h"
#include "command.h"
#include "shell.h"

using namespace std;

int main() {
	while (true) {
		int nowstatus = 0;
		std::string nowname = "";
		string nowlocation = "main";
		shell();
		if (nowstatus == -1) {
			break;
		}
	}
}
