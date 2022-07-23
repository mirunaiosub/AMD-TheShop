#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class User {
public:
	int m_id = 0;
	string m_username;
	string m_password;
	bool m_roleType = 0;

	void AddMod(string username) {
		string password, usern;
		int roletype;
		bool valid = 0;
		fstream read_user, write_user;
		read_user.open("users.txt", fstream::in);
		write_user.open("temp.txt", fstream::app |fstream::out);
		while (read_user >> usern >> password >> roletype) {
			write_user << usern << ' ';
			write_user << password << ' ';
			if (usern == username) {
				roletype = 1;
				valid = 1;
			}
			write_user << roletype;
			write_user << '\n';
		}
		if (valid)
			cout << "\nSuccess!!";
		else
			cout << "\nUsername not found.";
		read_user.close();
		write_user.close();
	}
};

void signup(User& x);
bool login(User& x);