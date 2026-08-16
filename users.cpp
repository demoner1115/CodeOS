#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void Log_in(int& nowstatus, string&nowname, string& nowlocation);
void Register(int& nowstatus, string&nowname, string& nowlocation);

void Log_in(int& nowstatus, string&nowname, string& nowlocation) { // 1. 참조자(&) 추가
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
				nowname = name; // nowname도 업데이트
				nowlocation = "data/" + name; // 로그인 시 위치를 사용자 폴더로 변경
				return;
			}
		}
		cout << "name or password is incorrect!" << endl;
	}
}

void Register(int& nowstatus, string&nowname, string& nowlocation) { // 1. 참조자(&) 추가
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
		fs::path userPath = fs::path("data") / name;

		std::error_code ec;
		fs::create_directories(userPath, ec);

		if (ec) {
			cout << "Directory creation failed: " << ec.message() << endl;
		}
		else {
			cout << "Directory created successfully at: "
				<< fs::absolute(userPath) << endl;
		}
		fs::path infoFile = userPath / "info.txt";

		ofstream info(infoFile);

		if (info.is_open()) {
			info << "username=" << name << endl;
			info.close();
		}
		else {
			cout << "info.txt creation failed!" << endl;
		}
		nowstatus = 1;
		nowname = name; // nowname도 업데이트
		nowlocation = "data/" + name; // 등록 시 위치를 사용자 폴더로 변경
		return;
	}
}