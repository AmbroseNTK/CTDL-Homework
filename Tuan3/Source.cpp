#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<stdarg.h>

#define LENGTH_LIMIT 100

using namespace std;

struct Student {
	char name[100];
	char studentID[100];
	float math;
	float physic;
	float chemistry;
};

typedef bool(*Compare)(Student*);

ostream& operator<<(ostream &os, const Student &student) {
	os << "\tName: " << student.name << endl;
	os << "\tStudent ID: " << student.studentID << endl;
	os << "\tMath: " << student.math << endl;
	os << "\tPhysic: " << student.physic << endl;
	os << "\tChemistry: " << student.chemistry << endl;
	return os;
}

void inputFromKeyboard(Student *&list, int &size) {
	int newSize = 0;
	cout << "Enter new size: ";
	fseek(stdin, 0, SEEK_END);
	cin >> newSize;
	int limit = size + newSize;
	for (int i = size; i < limit; i++) {
		cout << "Student #" << i << endl;
		cout << "\tName: ";
		fseek(stdin, 0, SEEK_END);
		gets_s((list + i)->name);
		fseek(stdin, 0, SEEK_END);
		cout << "\tStudent ID: ";
		gets_s((list + i)->studentID);
		cout << "\tMath: ";
		cin >> (list + i)->math;
		cout << "\tPhysic: ";
		cin >> (list + i)->physic;
		cout << "\tChemistry: ";
		cin >> (list + i)->chemistry;
		cout << "\n";
		size++;
	}
}

void inputFromFile(Student *&list, int &size) {
	size = 0;
	fseek(stdin, 0, SEEK_END);
	list = new Student[LENGTH_LIMIT];
	FILE *fin;
	cout << "Enter file directory: ";
	string dir = "";
	getline(cin, dir);
	fopen_s(&fin, dir.c_str(), "rb");
	if (fin != NULL) {
		while (!feof(fin)) {
			if (fread((list + size), sizeof(Student), 1, fin))
				size++;
		}
		fclose(fin);
		cout << "Loaded " << size << " row(s)" << endl;
	}
	else
		cout << "Could not open this file" << endl;
}

void saveToFile(Student *&list, int &size) {
	FILE *fout;
	string dir = "";
	cout << "Enter file directory: ";
	fseek(stdin, 0, SEEK_END);
	getline(cin, dir);
	fopen_s(&fout, dir.c_str(), "wb");
	if (fout != NULL) {
		fwrite(list, sizeof(Student), size, fout);
		fclose(fout);
		cout << "Saved" << endl;
	}
	else
		cout << "Could not save to this file" << endl;
}

int createMenu(int length, ...) {
	va_list params;
	va_start(params, length);
	char **textMenu = new char*[length];
	for (int i = 0; i < length; i++) {
		*(textMenu + i) = va_arg(params, char*);
	}
	va_end(params);
	for (int i = 0; i < length; i++) {
		cout << i << ". " << *(textMenu + i) << endl;
	}
	int choose = -1;
	cout << "Enter your selection: ";
	cin >> choose;
	return choose;
}

void viewData(Student *&list, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Student #" << i << endl;
		cout << *(list + i);
	}
}

bool pass(Student *student) {
	float avg = (student->math + student->physic + student->chemistry) / 3;
	if (avg >= 5 && (student->math*student->physic*student->chemistry) != 0)
		return true;
	return false;
}
bool fail(Student *student) {
	float avg = (student->math + student->physic + student->chemistry) / 3;
	if (avg <=5 || (student->math*student->physic*student->chemistry) == 0)
		return true;
	return false;
}
void generateList(Compare func, Student *list, int size) {
	for (int i = 0; i < size; i++) {
		if (func((list + i))) {
			cout <<"\t"<<i<<". "<< (list + i)->name << endl;
		}
	}
}

void main() {
	system("color 60");
	cout << "Students Management System" << endl;
	Student *list = new Student[LENGTH_LIMIT];
	int size = 0;
	bool exit = false;
	do {
		switch (createMenu(7, "Input from keyboard", "Input from file", "Save data to file", "View","Pass list","Fail list", "Exit")) {
		case 0:
			inputFromKeyboard(list, size);
			break;
		case 1:
			inputFromFile(list, size);
			break;
		case 2:
			saveToFile(list, size);
			break;
		case 3:
			viewData(list, size);
			break;
		case 4:
			cout << "Pass list-------------------" << endl;
			generateList(pass, list, size);
			break;
		case 5:
			cout << "Fail list-------------------" << endl;
			generateList(fail, list, size);
			break;
		case 6:
			exit = true;
			break;
		default:
			cout << "Function not found!" << endl;
			break;
		}
		cout << "Press any key to continue..." << endl;
		_getch();
		system("CLS");
	} while (!exit);
	_getch();
}