#include<iostream>
#include<Windows.h>

using namespace std;

struct Data {
	int a;
};

#include"LinkedList.h"

void printNode(Node *node) {
	cout << node->data.a << endl;
}

void main() {
	LinkedList list;
	init(list);
	Data d1, d2, d3, d4;
	d1.a = 1;
	d2.a = 2;
	d3.a = 3;
	d4.a = 4;
	addHead(list, d1);
	addHead(list, d2);
	addTail(list, d4);
	addTail(list, d3);
	cout << "After add" << endl;
	forEach(list, printNode);
	deleteHead(list);
	deleteHead(list);
	deleteTail(list);
	cout << "After delete" << endl;
	forEach(list, printNode);
	system("PAUSE");
}