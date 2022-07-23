#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "users.h"
#include "products.h"
#include "menu.h"
using namespace std;

User x;

void Menu(void) {

	int option;
	cout << "AMD Shop Menu:\n";
start:
	cout << "\n\nChoose an option:\n\n";
	cout << "1. Register\n";
	cout << "2. SignIn and Access to your menu\n";
	cout << "3. Exit\n\n";
	cout << "Your choice: "; 
	cin >> option;
	switch (option) {
	case 1: {system("cls"); signup(x); goto start; }
	case 2: {system("cls"); UserMenu(login(x)); goto start; }
	case 3: {system("cls"); exit(-99); }
	default: { cout << "No valid option!!\n";  Sleep(700); system("cls"); goto start; }
	}

}
void UserMenu(bool type) {
	while (1) {
		if (type)
		{
			int option;
			cout << "\n1. Add a product\n";
			cout << "2. List of products\n";
			cout << "3. Delete a product\n";
			cout << "4. Add admin\n";
			cout << "5. Return to Menu\n\n";
			cout << "Your choice: ";
			cin >> option;
			switch (option) {
			case 1: { system("cls"); ProductMenu(); break; }
			case 2: { system("cls"); ListProduct("products.txt"); break; }
			case 3: {
				char product_name[100];
				cout << "Product name: "; cin.ignore();
				cin.getline(product_name, 100, '\n');
				DeleteProduct(product_name, "products.txt");
				//system("cls"); 
				break;
			}
			case 4: {
				string username;
				cout << "\n username: ";
				cin >> username;
				x.AddMod(username); system("cls"); break;
			}
			case 5: {system("cls"); Menu(); break; }
			default: { cout << "No valid option!!\n"; Sleep(700); system("cls"); break; }
			}
		}
		else {
			int option;
			cout << "\n1. List of Products\n";
			cout << "2. Add a product to cart\n";
			cout << "3. Show the cart\n";
			cout << "4. Delete a product from cart\n";
			cout << "5. Return to Main Menu\n";
			cout << "Your choice: ";
			cin >> option;


			switch (option) {
			case 1: {
				system("cls");
				ListProduct("products.txt");
				break;
			}
			case 2: {
				char nameproduct[100];
				cin.ignore();
				cout << "\nName of product: "; 
				cin.getline(nameproduct, 100, '\n');
				AddProduct(nameproduct, x.m_username);
				system("cls");
				break;
			}
			case 3: { system("cls");
				string filename = x.m_username + "_cart.txt";
				ListProduct(filename); break;
			}
			case 4: { char product_name[100];
				cout << "Product name: "; cin.ignore();
				cin.getline(product_name, 100);
				string filename = x.m_username + "_cart.txt";
				DeleteProduct(product_name, filename);  system("cls"); break;
			}
			case 5: {
				system("cls");
				Menu();
				break;
			}
		
			default: { cout << "No valid option!!\n"; Sleep(700); system("cls"); cin.ignore(); break; }
			}
		}
	}



}
void ProductMenu(void) {
	int option;
	cout << "Choose type of product:";
	cout << "\n1. CPU\n";
	cout << "2. GPU\n";
	cout << "3. APU\n";
	cout << "Your choice: ";
	cin >> option;
	switch (option) {
	case 1: {
				CPU p; p.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break;
			}
	case 2: {
				GPU p; p.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break; 
			}
	case 3: {
				APU p; p.AddProduct().RegisterProduct("products.txt"); system("cls"); UserMenu(1); break; 
			}
	}
}