#include<iostream>
#include"Search.h"
#include"Sort.h"

using namespace std;

struct Student {
	int id;
	char *name;
	int age;
};

void assignStudent(Student &des, Student &src) {
	des.id = src.id;
	des.name = src.name;
	des.age = src.age;
}

void swapStudent(Student &studentA, Student &studentB) {
	Student temp;
	assignStudent(temp, studentA);
	assignStudent(studentA, studentB);
	assignStudent(studentB, temp);
}

void interchangeSortStd(Student *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((arr + i)->id < (arr + j)->id)
				swapStudent(*(arr + i),*(arr + j));
		}
	}
}
void bubbleSortStd(Student *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if ((arr + i)->id < (arr + j)->id)
				swapStudent(*(arr + i), *(arr + j));
		}
	}
}
void selectionSortStd(Student *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int pos = i + 1;
		for (int j = i + 1; j < n; j++) {
			if ((arr + pos)->id < (arr + j)->id)
				pos = j;
		}
		if (pos != i)
			swapStudent(*(arr + i), *(arr + pos));
	}
}
void insertionSortStd(Student *arr, int n) {
	int j = 0;
	for (int i = 1; i < n; i++) {
		Student key; 
		assignStudent(key,arr[i]);
		for (j = i - 1; j > 0 && (arr + j)->id < key.id; j--)
			swapStudent(*(arr + j), *(arr + j - 1));
		swapStudent(*(arr + j), key);
	}
}

void printArr(int *arr, int n) {
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}
void printArrStd(Student *arr, int n) {
	for (int i = 0; i < n; i++)
		cout << "ID = " << (arr + i)->id << "; Name = " << (arr + i)->name << "; Age = " << (arr + i)->age<< endl;
}
void main() {
	int arr[] = { 1,2,7,1,4,3 };
	int n = 6;
	cout << binarySearch(arr, n, 1) << endl;
	insertionSort(arr, n, decrease);
	printArr(arr, n);

	Student *listStudent = new Student[3];
	listStudent[0].id = 10;
	listStudent[0].name = "Bo";
	listStudent[0].age = 18;

	listStudent[1].id = 5;
	listStudent[1].name = "Ga";
	listStudent[1].age = 20;

	listStudent[2].id = 20;
	listStudent[2].name = "Cho";
	listStudent[2].age = 15;
	
	
	/*insertionSortStd(listStudent, 3);
	printArrStd(listStudent, 3);*/
	cin.get();
}