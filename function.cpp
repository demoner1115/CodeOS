#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

void Log_in(int& nowstatus);
void Register(int& nowstatus);
void terminal(string nowlocation, int& nowstatus);

void terminal(string nowlocation, int& nowstatus) {
	cout << "Welcome to the terminal!" << endl;
	while (true) {
		string command;
		cout << nowlocation << ": ";
		cin >> command;
		if (nowstatus == 0) {
			if (command == "login") {
				Log_in(nowstatus);
			}
			else if (command == "register") {
				Register(nowstatus);
			}
			else if (command == "exit") {
				break;
			}
			else if (command == "help") {
				cout << "Available commands: login, register, exit, help" << endl;
			}
			else {
				cout << "error" << endl;
			}
		}
		else if (nowstatus == 1) {
			if (command == "login") {
				Log_in(nowstatus);
			}
			else if (command == "register") {
				Register(nowstatus);
			}
			else if (command == "exit") {
				break;
			}
			else if (command == "help") {
				cout << "Available commands: login, register, exit, help" << endl;
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

void Log_in(int& nowstatus) { // 1. 참조자(&) 추가
	if (nowstatus == 0) {
		vector<string> v;
		ifstream file("users.txt");

		string name, PW;
		string s;

		while (getline(file, s)) {
			v.push_back(s);
		}
		file.close();

		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your password: ";
		cin >> PW;

		// 2. 전체 목록을 검사
		for (int i = 0; i < v.size(); i += 2) {
			// v[i]가 이름, v[i+1]이 비밀번호인지 확인 (인덱스 초과 방지)
			if (i + 1 < v.size() && v[i] == name && v[i + 1] == PW) {
				cout << "Login successful!" << endl;
				nowstatus = 1; // 이제 원본 값이 1로 변경됩니다!
				return;
			}
		}
		cout << "name or password is incorrect!" << endl;
	}
}

void Register(int& nowstatus) { // 1. 참조자(&) 추가
	if (nowstatus == 0) {
		vector<string> v;
		ifstream file("users.txt");
		string name, PW;
		string s;
		while (getline(file, s)) {
			v.push_back(s);
		}
		file.close();
		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your password: ";
		cin >> PW;
		for (int i = 0; i < v.size(); i += 2)
		{
			if (v[i] == name)
			{
				cout << "This name is already registered!" << endl;
				return;
			}
		}
		ofstream outfile("users.txt", ios::app);
		outfile << name << endl;
		outfile << PW << endl;
		outfile.close();
		cout << "Register successful!" << endl;
		nowstatus = 1;
		return;
	}
}