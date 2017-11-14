#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

typedef int(MoveType)(int, int);

struct Book {
	char ISBN[10];
	char name[50];
	float price;
};

struct CList {
	int maximum = 100;
	Book *data;
	int length = 0;
};

void init(CList &list,int max) {
	list.data = new Book[max];
	list.maximum = max;
	list.length = 0;
}

bool isNotFull(CList list){
	return list.maximum - list.length;
}

int moveLeft(int at, int step) {
	return at - step;
}

int moveRight(int at, int step) {
	return at + step;
}

bool shift(CList &list, int at, int step, MoveType func) {
	int next = func(at, step);
	if (next > list.maximum || next < 0)
		return false;
	*(list.data + next) = *(list.data + at);
}

bool addTop(CList &list, Book b) {
	if (!isNotFull(list))
		return false;
	for (int i = list.length; i >= 0; i--)
		if (shift(list, i, 1, moveRight) == false)
			return false;
	list.data[0] = b;
	list.length++;
	return true;
}

bool addNTop(CList &list, CList others) {
	if (others.length + list.length > list.maximum)
		return false;
	for (int i = list.length; i >= 0; i--) {
		if (shift(list, i, others.length, moveRight) == false)
			return false;
	}
	for (int i = 0; i < others.length; i++) {
		list.data[i] = others.data[i];
	}
	list.length += others.length;
	return true;
}

bool addMiddle(CList &list, Book b, int at) {
	
	if (at<0 || at>list.maximum || isNotFull(list))
		return false;
	for (int i = list.length; i >= at; i--) {
		if (shift(list, i, 1, moveRight) == false)
			return false;
	}
	*(list.data + at) = b;
	list.length++;
	return true;
}

bool addNMiddle(CList &list, CList others, int at) {
	if (others.length + list.length > list.maximum || at<0 || at>list.maximum)
		return false;
	for (int i = list.length; i >= at; i--) {
		if (shift(list, i, others.length, moveRight) == false)
			return false;
	}
	for (int i = 0; i < others.length; i++)
		*(list.data + at + i) = *(others.data + i);
	list.length += others.length;
	return true;
}

bool addBottom(CList &list, Book b) {
	if (isNotFull(list))
		return false;
	*(list.data + list.length) = b;
	list.length++;
	return true;
}

bool addNBottom(CList &list, CList others) {
	if (list.length + others.length > list.maximum)
		return false;
	for (int i = 0; i < others.length; i++) {
		*(list.data + list.length) = *(others.data + i);
		list.length++;
	}
	return true;
}

bool deleteTopK(CList &list, int k) {
	if (list.length < k)
		return false;
	for (int i = k; i < list.length; i++) {
		shift(list, i, k, moveLeft);
	}
	list.length -= k;
	return true;
}
bool deleteBottomK(CList &list, int k) {
	if (list.length < k)
		return false;
	list.length -= k;
	return true;
}
bool deleteMiddleK(CList &list, int at, int k) {
	if (list.length < at + k || at<0 || at>list.length)
		return false;
	for (int i = at+k; i < list.length; i++) {
		shift(list, i, k, moveLeft);
	}
	list.length -= k;
	return true;

}
void inputABook(Book &b) {
	cout << "\tISBN: ";
	fseek(stdin, 0, SEEK_END);
	gets_s(b.ISBN);
	cout << endl << "\tName: ";
	gets_s(b.name);
	fseek(stdin, 0, SEEK_END);
	cout << endl << "\tPrice: ";
	cin >> b.price;
}
void input(CList &list, int n) {
	for (int i = 0; i < n; i++) {
		Book b;
		cout << "Enter book #" << list.length << endl;
		inputABook(b);
		addTop(list, b);
	}
}
void printList(CList list) {
	for (int i = 0; i < list.length; i++) {
		cout << "Book #" << i << endl;
		cout << "\tISBN: ";
		puts(list.data[i].ISBN);
		cout << "\tName: ";
		puts(list.data[i].name);
		cout << "\tPrice: " << list.data[i].price << endl;
	}

}
void main() {
	CList list1;
	cout << "List1 Max Length: " << endl;
	int max;
	cin >> max;
	init(list1, max);
	cout << "List1 new element: " << endl;
	int n;
	cin >> n;
	input(list1, n);
	
	CList list2;
	cout << "List2 Max Length: " << endl;
	cin >> max;
	init(list2, max);
	cout << "List2 new element: " << endl;
	cin >> n;
	input(list2, n);

	int pos = 0;
	cout << "Insert list2 into list1 at: ";
	cin >> pos;
	addNMiddle(list1, list2, pos);

	printList(list1);

	cout << "Delete list1 at: ";
	cin >> pos;
	int quan = 0;
	cout << "Deletion quantity: ";
	cin >> quan;

	deleteMiddleK(list1, pos, quan);
	printList(list1);

	system("PAUSE");
}