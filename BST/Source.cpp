#include<iostream>

using namespace std;

struct Data {
	int num;
};

#include"BST.h"

void printData(Data data) {
	cout << data.num;
}

Data inputData() {
	Data d;
	cout << "num = ";
	cin >> d.num;
	return d;
}

int compare(Data first, Data second) {
	if (second.num > first.num)
		return 1;
	else if (second.num < first.num)
		return -1;
	return 0;
}

void printNode(BNode *input, BNode **&args) {
	printData(input->data);
}

void main() {
	BST tree;
	init(tree);
	createBST(tree, inputData, compare);
	forEach(tree.pRoot, "LNR", printNode);
	system("PAUSE");
}