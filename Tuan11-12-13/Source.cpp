#include<iostream>
#include<Windows.h>

#define MAX_N 100

using namespace std;

struct Data {
	char bookName[MAX_N];
	double price;
};

Data emptyData;

#include"Stack.h"
#include"Queue.h"
#include"BTree.h"

Data inputData() {
	Data data;
	fseek(stdin, 0, SEEK_END);
	cout << "Enter book name: ";
	gets_s(data.bookName);
	cout << "Enter book price: ";
	fseek(stdin, 0, SEEK_END);
	cin >> data.price;
	fseek(stdin, 0, SEEK_END);
	return data;
}

void outputData(Data data) {
	if (&data != NULL) {
		cout << "Book name: " << data.bookName << "; price = " << data.price << endl;
	}
	else
		cout << "NULL DATA" << endl;
}

void demoStack() {
	Stack stack;
	init(stack);
	push(inputData(), stack);
	push(inputData(), stack);
	push(inputData(), stack);

	outputData(pop(stack));
	outputData(getTop(stack));
	outputData(pop(stack));
	outputData(pop(stack));
	outputData(pop(stack));
}

void demoQueue() {
	Queue queue;
	init(queue);
	push(inputData(), queue);
	push(inputData(), queue);
	push(inputData(), queue);

	outputData(pop(queue));
	outputData(getTop(queue));
	outputData(pop(queue));
	outputData(pop(queue));
	outputData(pop(queue));
}

void demoBTree() {
	BTree bTree;
	init(bTree);
	createBTree(bTree.pRoot,inputData,outputData);
}

void main() {
	demoQueue();
	system("PAUSE");
}