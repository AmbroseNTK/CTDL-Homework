
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

Node *createNode(Data data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->pNext = NULL;
	return newNode;
}

void push(Data data, Queue &queue) {
	Node *n = createNode(data);
	if (queue.pHead == NULL) {
		queue.pHead = queue.pTail = n;
	}
	else {
		queue.pTail->pNext = n;
		queue.pTail = queue.pTail->pNext;
	}
}

Data pop(Queue &queue) {
	if (queue.pHead == NULL) {
		return emptyData;
	}
	else {
		Data head = queue.pHead->data;
		queue.pHead = queue.pHead->pNext;
		return head;
	}
}

Data getTop(Queue &queue) {
	if (queue.pHead == NULL) {
		return emptyData;
	}
	else {
		return queue.pHead->data;
	}
}
