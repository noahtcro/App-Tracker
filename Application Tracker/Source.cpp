#include <iostream> //cout and cin functions
#include <cstdlib> //math functions
#include <fstream> //ofstream functions
#include <string> //getline functions
#include <vector> //vector functions

/*
* Open for writing
std::fstream::out
* Open for reading
std::fstream::in
* Open for editing
std::fstream::app
*/

void createFile();
void writeFile();
void readFile();
void editFile();

int main() {
	int menu = 0;
	createFile();

	do {
		std::cout << "1. Create new application" << std::endl;
		std::cout << "2. View outstanding applications" << std::endl;
		std::cout << "3. Update status of applications" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "Please select an option and press enter: ";
		std::cin >> menu;

		switch (menu) {
		case 1:
			writeFile();
			break;
		case 2:
			readFile();
			break;
		case 3:
			editFile();
			break;
		case 4:
			break;
		}
	} while (menu != 4);
	return 0;
}

void createFile() {
	std::fstream file;
	file.open("apps.txt");
	if (file) {
		file.close();
		std::cout << "File found." << std::endl;
		return;
	}
	else {
		file.open("apps.txt", std::fstream::out);

		if (!file) {
			file.close();
			std::cout << "Error" << std::endl;
			return;
		}

		file.close();
		std::cout << "File created." << std::endl;
		return;
	}
}

void writeFile() {
	system("cls"); //clear screen
	std::fstream file;
	std::string company;
	std::string position;
	std::string date;
	std::string status = "Pending";

	file.open("apps.txt", std::fstream::app);

	std::cout << "Name of the company: ";
	std::cin >> company;

	system("cls");
	std::cout << "Name of the position: ";
	std::cin >> position;

	system("cls");
	std::cout << "Date of application: ";
	std::cin >> date;

	system("cls");
	std::cout << "Application is pending." << std::endl;
	system("pause");

	file << company << std::endl;
	file << position << std::endl;
	file << date << std::endl;
	file << status << std::endl;

	file.close();
	system("cls");

	return;
}

void readFile() {
	system("cls");
	std::fstream file;
	std::string text;
	int lead = 1;
	int num = 1;
	int row = 0;

	file.open("apps.txt", std::fstream::in);

	while (getline(file, text)) {
		if (lead == 1) {
			std::cout << num << ". ";
			num++;
			lead++;
		}
		else if (lead < 4) {
			lead++;
		}
		else if (lead == 4) {
			lead = 1;
		}

		if (row < 3) {
			std::cout << text << "\t \t \t";
			row++;
		}
		else {
			std::cout << text << std::endl;
			row = 0;
		}
	}

	file.close();
	system("pause");
	system("cls");

	return;
}

void editFile() {
	system("cls");
	std::fstream file;
	std::string text;
	int lead = 1;
	int num = 1;
	int row = 0;
	int record = 0;
	int choice = 0;

	file.open("apps.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	std::vector<std::string> edit;

	while (getline(file, text)) {
		edit.push_back(text);

		if (lead == 1) {
			std::cout << num << ". ";
			num++;
			lead++;
		}
		else if (lead < 4) {
			lead++;
		}
		else if (lead == 4) {
			lead = 1;
		}

		if (row < 3) {
			std::cout << text << "\t \t \t";
			row++;
		}
		else {
			std::cout << text << std::endl;
			row = 0;
		}
	}

	file.close();

	std::cout << std::endl;

	std::cout << "Which record status would you like to change: ";
	std::cin >> record;
	record = record + 2;

	system("cls");
	std::cout << "1. Accepted" << std::endl;
	std::cout << "2. Denied" << std::endl;
	std::cout << "3. Pending" << std::endl;
	std::cout << "What should the status be changed to: ";
	std::cin >> choice;

	
	switch (choice) {
	case 1:
		edit.at(record) = "Accepted";
		break;
	case 2:
		edit.at(record) = "Denied";
		break;
	case 3:
		edit.at(record) = "Pending";
		break;
	}

	file.open("apps.txt", std::fstream::in | std::fstream::out);

	for (int i = 0; i < edit.size(); i++) {
		file << edit.at(i) << std::endl;
	}

	file.close();
	system("pause");
	system("cls");
}