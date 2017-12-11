#pragma once

struct Node {
	Data data;
	Node *pNext;
};
struct Queue {
	Node *pHead;
	Node *pTail;
};

void init(Queue &queue) {
	queue.pHead = NULL;
	queue.pTail = NULL;
}
bool isEmpty(Queue queue) {
	if (queue.pHead == NULL)
		return true;
	return false;
}

void push(Queue &queue, Data data) {
	Node *node = new Node;
	node->data = data;
	node->pNext = NULL;
	if (isEmpty(queue)) {
		queue.pHead = node;
		queue.pTail = node;
	}
	else {
		queue.pTail->pNext = node;
	}
}

Data pop(Queue &queue) {
	Data result = queue.pHead->data;
	queue.pHead = queue.pHead->pNext;
	return result;
}

Data getTop(Queue &queue) {
	Data result = queue.pHead->data;
	return result;
}
