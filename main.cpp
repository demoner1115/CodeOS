#include <iostream>
#include "users.h"
#include "terminal.h"

using namespace std;

int main() {
	while (true) {
		int nowstatus = 0;
		std::string nowname = "";
		string nowlocation = "main";
		terminal(nowlocation, nowstatus, nowname);
		if (nowstatus == -1) {
			break;
		}
	}
}
