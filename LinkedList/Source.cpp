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

void equal(Node *node, Node **args) {
	if (node->data.a == args[0]->data.a) {
		args[1] = node;
	}
}

Node* lookingFor(LinkedList list, Data key) {
	Node **args = new Node*[2];
	args[0] = createNode(key);
	args[1] = new Node;
	forEach(list, equal, args);
	return args[1];
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
	
	cout << "Looking for: 3" << endl;
	Data key;
	key.a = 3;
	printNode(lookingFor(list, key));

	cout << "Looking for: 7" << endl;
	key.a = 7;
	printNode(lookingFor(list, key));


	deleteHead(list);
	deleteHead(list);
	deleteTail(list);
	cout << "After delete" << endl;
	forEach(list, printNode);
	system("PAUSE");
}