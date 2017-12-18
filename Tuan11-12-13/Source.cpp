#include<iostream>
#include<Windows.h>
#include<iomanip>

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

void outputData(Data data,int offset) {
	if (&data != NULL) {
		for (int i = 0; i < offset; i++)
			cout << "-";
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

	outputData(pop(stack),0);
	outputData(getTop(stack),0);
	outputData(pop(stack),0);
	outputData(pop(stack),0);
	outputData(pop(stack),0);
}

void demoQueue() {
	Queue queue;
	init(queue);
	push(inputData(), queue);
	push(inputData(), queue);
	push(inputData(), queue);

	outputData(pop(queue),0);
	outputData(getTop(queue),0);
	outputData(pop(queue),0);
	outputData(pop(queue),0);
	outputData(pop(queue),0);
}

void demoBTree() {
	BTree bTree;
	init(bTree);
	createBTree(bTree.pRoot,inputData,outputData);
	printTree(bTree.pRoot, 0, outputData);
}

void main() {
	demoBTree();
	system("PAUSE");
}