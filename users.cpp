#include <iostream>
#include <string>
#include <Windows.h>
#include "users.h"
using namespace std;

void signup(User& x) {
start:
	static int id = 1;
	cout << "username: ";
	cin >> x.m_username;
	cout << "password: ";
	cin >> x.m_password;
	cout << "roletype: ";
	cin >> x.m_roleType;
	fstream record;
	record.open("users.txt", fstream::app | fstream::out);
	record << x.m_username << ' ';
	record << x.m_password << ' ';
	record << x.m_roleType;
	record << '\n';
	record.close();
	cout << "Success!\n";
}
bool login(User& x) {
start_login:
	int attempt = 0;
	string username, password, usern, pass;
	int lgid, roletype;

	system("cls");
	cout << "username: ";
	cin >> username;
	cout << "password: ";
	cin >> password;
	fstream loginfin;
	loginfin.open("users.txt", fstream::in);


	while (loginfin >> lgid >> usern >> pass >> roletype)
	{
		if (username == usern && password == pass) {
			attempt = 1;
			cout << "Access permitted!";
			loginfin.close();
			x.m_id = lgid;
			x.m_password = password;
			x.m_username = username;
			x.m_roleType = roletype;
			break;
		}

	}
	if (attempt == 0) {
		cout << "Wrong username or password. Try again!";
		Sleep(700);
		goto start_login;
	}
	return roletype;
}
