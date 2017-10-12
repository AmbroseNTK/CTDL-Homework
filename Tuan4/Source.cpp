//Nguyen Tuan Kiet - BT Tuan 4
#include<iostream>
#include<conio.h>

#define MAX 1000
#define MAX_CHAR 100

using namespace std;

struct Element {
	char data;
	int quality;
};

void convertStrToLower(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void strSplit(char **&result, int &length) {
	length = 0;
	result = new char*[MAX];
	char *input = NULL;
	
	do {
		*(result + length) = new char[MAX_CHAR];
		cin >> *(result + length);
		convertStrToLower(*(result + length));
		length++;
	} while (cin.get() != '\n');
}

Element* countChar(char *str,int &size) {
	int len = strlen(str);
	size = 0;
	bool isNew = true;
	Element *result = new Element[len];
	for (int i = 0; i < len; i++) {
		isNew = true;
		for (int j = 0; j < size; j++) {
			if ((result + j)->data == *(str + i)) {
				(result + j)->quality++;
				isNew = false;
				break;
			}
		}
		if (isNew) {
			(result + size)->data = *(str + i);
			(result + size)->quality = 1;
			size++;
		}
	}
	return result;
}

void printCharTable(Element *table,int size) {
	cout << "Char\tQuality" << endl;
	for (int i = 0; i < size; i++) {
		cout << (table + i)->data << "\t" << (table + i)->quality << endl;
	}
}



void main() {
	cout << "Enter a string: ";
	char **result = NULL;
	int length = 0;
	strSplit(result, length);
	//Cau C
	cout << "Solution C:" << endl;
	for (int i = 0; i < length; i++)
		cout << *(result + i) << endl;
	//Cau D
	cout << "Solution D:" << endl;
	for (int i = length-1; i >= 0; i--)
		cout << *(result + i) << " ";
	//Cau F
	cout << endl << "Solution F:" << endl;
	for (int i = 0; i < length; i++) {
		int subLen = strlen(*(result + i));
		
		for (int j = 0; j < subLen; j++) {
			if (j == 0) {
				cout << (char)(toupper((*(*(result + i) + j))));
			}
			else
				cout << *(*(result + i) + j);
		}
		cout << " ";
	}
	cout << endl;
	cout << endl << "Solution 1:" << endl;
	cout << "Enter another string: ";
	char s[MAX_CHAR];
	gets_s(s);
	int len = strlen(s);
	for (int j = len - 1; j >= 0; j--) {
		cout << s[j];
	}
	cout << endl;
	cout << endl << "Solution 2:" << endl;
	int charTableSize = 0;
	Element *table = countChar(s, charTableSize);
	printCharTable(table, charTableSize);
	cout << endl;
	cout << endl << "Solution 3:" << endl;
	//Make an email
	char email[MAX] = { '\0' };
	strcat_s(email, MAX, (result[length - 1]));
	strcat_s(email, MAX, ".");
	for (int i = 0; i < length - 1; i++)
		strcat_s(email, MAX, result[i]);
	strcat_s(email,MAX, "@hoasen.edu.vn");
	cout << email << endl;
	//Make a student email
	cout << endl << "Solution 4:" << endl;
	cout << "Enter your student ID: ";
	char studentID[MAX] = { '\0' };
	cin >> studentID;
	cout << "Student Email" << endl;
	char studentEmail[MAX] = { '\0' };
	strcat_s(studentEmail, MAX, (result[length - 1]));
	strcat_s(studentEmail, MAX, ".");
	for (int i = 0; i < length - 1; i++)
		strcat_s(studentEmail, MAX,(*(result+i)+0));
	strcat_s(studentEmail, MAX, (studentID + strlen(studentID) - 4));
	strcat_s(studentEmail, MAX, "@sinhvien.hoasen.edu.vn");
	cout << studentEmail << endl;
	_getch();
}