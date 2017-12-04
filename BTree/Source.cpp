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

void maxNode(BNode *input, BNode ** &params) {
	if (params[0] == NULL) {
		params[0] = input;
	}
	else {
		if (params[0]->data.n < input->data.n)
			params[0] = input;
	}
}

void printTree(BNode *input, BNode ** &params) {
	cout << input->data.n << " ";
}

void main() {
	BTree bTree;
	init(bTree);
	createBTree(bTree.pRoot, inputData, printData);
	forEach(bTree.pRoot, "NLR", printTree);
	cout << endl;
	BNode **params = new BNode*[0];
	params[0] = new BNode;
	forEach(bTree.pRoot, "NLR", maxNode, params);
	printData(params[0]);
	system("PAUSE");
}