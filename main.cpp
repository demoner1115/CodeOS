#include <iostream>
#include "function.h"

using namespace std;

int main() {
	while (true) {
		int nowstatus = 0;
		string nowlocation = "main";
		terminal(nowlocation, nowstatus);
		if (nowstatus == -1) {
			break;
		}
	}
}
