#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void signup() {
	string password, username;
	cout << "Enter Username : ";
	cin >> username;
	string filee = username + ".txt";
	ifstream file(filee);
	while (file) {
		cout << "Username is already registered. Enter another username : ";
		file.close();
		cin >> username;
		string filee = username + ".txt";
		ifstream file(filee);
	}
	file.close();
	ofstream nfile(filee);
	if (nfile.is_open()) {
		cout << "Enter your password : ";
		cin >> password;
		nfile << password;
		nfile.close();
		cout << "Account Created! Welcome " << username << "!" << endl;
		exit(0);
	}
	else {
		cout << "Error! Unable to open file!" << endl;
		exit(1);
	}
}

void login() {
	string username, password;
	cout << "Enter your username : ";
	cin >> username;
	string filee = username + ".txt";
	ifstream file(filee);
	if (file) {
		cout << "Enter Your password : ";
		cin >> password;
		string registeredpass;
		getline(file, registeredpass);
		if (password == registeredpass) {
			cout << "Welcome " << username << "!" << endl;
		}
		else {
			cout << "Password is incorrect! Re-enter your password : ";
			cin >> password;
			if (password == registeredpass) {
				cout << "Welcome " << username << "!" << endl;
			}
			else {
				cout << "Only Two attempts allowed! Try Logging in later." << endl;
			}
		}
		file.close();
		exit(0);
	}
	else {
		cout << "Username Doesn't Exist! Do you want to Signup? (Yes / No / 0 (to exit))" << endl;
		string yesno;
		cin >> yesno;
		for (auto& x : yesno) { //lowercase
			x = tolower(x);
		}
		while (yesno != "0" && yesno != "yes" && yesno != "no") {
			cout << "Option isnt available. Enter Again!" << endl;
			cin >> yesno;
			for (auto& x : yesno) {
				x = tolower(x);
			}
		}
		if (yesno == "yes") {
			signup();
		}
		else {
			cout << "Program Exitted Succesfully!" << endl;
			exit(0);
		}
	}
}

int main() {
	int choice = 0;
	cout << "What do you want to do? \n 1. Login \n 2. Signup \n";
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "Invalid Input! Enter a correct number : ";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		login();
		break;
	case 2:
		signup();
		break;
	};
	return 0;
}