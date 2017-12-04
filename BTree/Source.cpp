#include<iostream>
#include<Windows.h>

using namespace std;

struct Data {
	char n;
};

#include"BTree.h"

Data inputData() {
	Data d;
	cout << "\tEnter value: ";
	cin >> d.n;
	return d;
}

void printData(BNode *node) {
	if (node != NULL)
		cout << node->data.n << endl;
	else
		cout << "Null data" << endl;
}

void printTree(BNode *input, BNode **params) {
	cout << input->data.n << " ";
}

void main() {
	BTree bTree;
	init(bTree);
	createBTree(bTree.pRoot, inputData, printData);
	forEach(bTree.pRoot, "NLR", printTree, NULL);
	cout << endl;
	system("PAUSE");
}