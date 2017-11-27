#pragma once

struct Node {
	Data data;
	Node *pNext;
};

struct LinkedList {

	Node *pHead;
	Node *pTail;

};

typedef void (*Enumerator)(Node*);
typedef void (*Enumerators)(Node*, Node**);

Node* createNode(Data data) {
	Node *node = new Node;
	node->data = data;
	node->pNext = NULL;
	return node;
}

void init(LinkedList &list) {
	list.pHead = NULL;
	list.pTail = NULL;
}

void addHead(LinkedList &list, Data data) {
	Node *node = createNode(data);
	if (list.pHead == NULL) {
		list.pHead = node;
		list.pTail = node;
	}
	else {
		node->pNext = list.pHead;
		list.pHead = node;
	}
}
void addTail(LinkedList &list, Data data) {
	Node *node = createNode(data);
	if (list.pTail == NULL) {
		list.pTail = node;
		list.pHead = node;
	}
	else {
		list.pTail->pNext = node;
		list.pTail = node;
	}
}

void deleteHead(LinkedList &list) {
	if (list.pHead != NULL) {
		Node *deletion = list.pHead;
		list.pHead = list.pHead->pNext;
		delete deletion;
	}
}

void deleteTail(LinkedList &list) {
	if (list.pTail != NULL) {
		Node *deletion = list.pTail;
		Node *previous = new Node;
		for (previous = list.pHead; previous->pNext->pNext != NULL; previous = previous->pNext);
		previous->pNext = NULL;
		list.pTail = previous;
		delete deletion;
	}
}

void forEach(LinkedList &list, Enumerator doSomething) {
	for (Node *node = list.pHead; node != NULL; node = node->pNext) {
		doSomething(node);
	}
}

void forEach(LinkedList &list, Enumerators doSomething, Node **addition) {
	for (Node *node = list.pHead; node != NULL; node = node->pNext) {
		doSomething(node, addition);
	}
}
