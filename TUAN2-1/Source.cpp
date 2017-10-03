#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdarg.h>
#include<string>

#define WORK_FINISHED "finished"
#define WORK_ERROR "error"
#define WORK_UNFINISHED "unfinished"

#define MAX_READ 1000
using namespace std;

struct Homework {
	string workID;
	string workName;
	string status;
};
int createMenu(int length, ...) {
	va_list params;
	int choose = -1;
	system("color 1E");
	va_start(params, length);
	char **menuText = new char*[length];
	for (int i = 0; i < length; i++) {
		menuText[i] = va_arg(params, char*);
	}
	va_end(params);
	bool exit = false;
	do {
		printf("\nPress any key to show selections\n");
		switch (_getch()) {
		case 72:
			choose--;
			if (choose == -1)
				choose = length-1;
			break;
		case 80:
			choose++;
			if (choose == length)
				choose = 0;
			break;
		case 13:
			exit = true;
			break;
		}
		system("CLS");
		for (int i = 0; i < length; i++) {
			if (i == choose)
				printf("select>");
			printf("\t%s\n", menuText[i]);
		}
		printf("Please use Up and Down to change your select. Then press Enter\n");
	} while (!exit);
	return choose;
}
void addNewHomework(Homework list[],int &size) {
	printf("Function: Add a new homework to array\n");
	fseek(stdin, 0, SEEK_END);
	printf("Enter homework's ID:");
	getline(cin, list[size].workID);
	printf("Enter homework's name:");
	getline(cin, list[size].workName);
	printf("Select homework's status:\n");
	switch (createMenu(3,WORK_FINISHED,WORK_ERROR,WORK_UNFINISHED)){
	case 0:
		list[size].status = WORK_FINISHED;
		break;
	case 1:
		list[size].status = WORK_ERROR;
		break;
	case 2:
		list[size].status = WORK_UNFINISHED;
		break;

	}
	size++;
}
void addMultipleHomework(Homework list[], int &oldSize) {
	int newSize = 0;
	printf("Enter homework quality: \n");
	scanf_s("%d", &newSize);
	int limit = oldSize + newSize;
	for (int i = oldSize; i < limit; i++) {
		system("CLS");
		printf("Enter homework #%d data:\n", i);
		addNewHomework(list, oldSize);
	}
}
void showHomeworkByIndex(Homework list[], int index) {
	printf("%d\t%s\t%s\t%s\n", index, list[index].workID.c_str(), list[index].workName.c_str(), list[index].status.c_str());
}
void showHomework(Homework list[], int size) {
	system("CLS");
	printf("Function: Show All\n");
	printf("No.\tID\tName\tStatus\n");
	for (int i = 0; i < size; i++) {
		showHomeworkByIndex(list, i);
	}

}
void saveToFile(Homework list[], int size) {
	system("CLS");
	printf("Function: Save to file\n");
	string dir = "";
	printf("Enter file directory: \n");
	getline(cin, dir);
	FILE *fout;
	fopen_s(&fout, dir.c_str(), "wb");
	if (fout != NULL) {
		fwrite(list, sizeof(Homework), size, fout);
		printf("Saved\n");
		fclose(fout);
	}
	else {
		printf("\nCannot save this file\n");
	}
}
void readFromFile(Homework list[], int &size) {
	system("CLS");
	printf("Function: Read from file\n");
	string dir = "";
	printf("Enter file directory: \n");
	getline(cin, dir);
	FILE *fin;
	fopen_s(&fin, dir.c_str(), "rb");
	if (fin != NULL) {
		int length = 0;
		while (!feof(fin)) {
			if (fread(list + length, sizeof(Homework), 1, fin));
				length++;
		}
		size = length - 1;
		fclose(fin);
		printf("\nDone\n");
	}
	else {
		printf("\nCannot open this file\n");
	}
}
int searchBy(string data, int col, Homework result[], Homework list[], int size) {
	int rSize = 0;
	for (int i = 0; i < size; i++) {
		switch (col) {
		case 0:
			if (strcmp(list[i].workID.c_str(), data.c_str())==0){
				result[rSize] = list[i];
				rSize++;
			}
			break;
		case 1:
			if (strcmp(list[i].workName.c_str(), data.c_str())==0) {
				result[rSize] = list[i];
				rSize++;
			}
			break;
		case 2:
			if (strcmp(list[i].status.c_str(), data.c_str())==0) {
				result[rSize] = list[i];
				rSize++;
			}
			break;
		}
	}
	return rSize;

}
void searchFunction(Homework list[], int size) {
	int choose = createMenu(3, "Search by ID", "Search by name", "Search by status");
	string data = "";
	if(choose==2)
		switch (createMenu(3, WORK_FINISHED, WORK_ERROR, WORK_UNFINISHED)) {
		case 0:
			data = WORK_FINISHED;
			break;
		case 1:
			data = WORK_ERROR;
			break;
		case 2:
			data = WORK_UNFINISHED;
			break;
		}
	else {
		printf("Enter search keywords: ");
		getline(cin, data);
	}
	Homework result[MAX_READ];
	int length = searchBy(data, choose, result, list, size);
	if (length == 0)
		printf("No data\n");
	else {
		showHomework(result, length);
		printf("Total :%d row(s)", length);
	}
}
void calcScore(Homework list[], int size) {
	float score = 0;
	string status[] = { WORK_FINISHED,WORK_ERROR};
	int scoreRef[] = { 10,5 };
	for (int i = 0; i < 2; i++) {
		Homework result[MAX_READ];
		int length = searchBy(status[i], 2, result, list, size);
		score += length*scoreRef[i];
	}
	printf("Total score: %f\n", score / size);
}
void main() {
	Homework listHomework[MAX_READ];
	int size = 0;
	printf("\tHOMEWORK MANAGEMENT APPLICATION\nPress Key Down to start");
	bool exit = false;
	do {
		switch (createMenu(8, "Add a new homework to array", "Add multiple homework to array", "Save to file", "Read from file", "Show all", "Search","Score Calculating", "Exit")) {
		case 0:
			system("CLS");
			addNewHomework(listHomework, size);
			break;
		case 1:
			addMultipleHomework(listHomework, size);
			break;
		case 2:
			saveToFile(listHomework, size);
			break;
		case 3:
			readFromFile(listHomework, size);
			break;
		case 4:
			showHomework(listHomework, size);
			break;
		case 5:
			searchFunction(listHomework, size);
			break;
		case 6:
			calcScore(listHomework, size);
			break;
		case 7:
			exit = true;
			break;
		default:
			printf("\nFunction not found!\n");
		}
	} while (!exit);

	system("PAUSE");
}