
struct BNode {
	Data data;
	BNode *pL;
	BNode *pR;
};

typedef void(*Enumerator)(BNode*, BNode** &);

typedef Data(*InputMethod)();

typedef void(*PrintMethod)(BNode *);

struct BTree {
	BNode *pRoot;
};

BNode* createBNode(Data data) {
	BNode *node = new BNode;
	if (node != NULL) {
		node->data = data;
		node->pL = NULL;
		node->pR = NULL;
	}
	return node;
}

void init(BTree &tree) {
	tree.pRoot = NULL;
}

void createBTree(BNode* &pRoot, InputMethod input, PrintMethod printData) {

	BNode *newNode = createBNode(input());
	if (newNode != NULL) {
		if (pRoot == NULL)
			pRoot = newNode;

		if (pRoot->pL == NULL) {
			cout << "Current node: ";
			printData(pRoot);
			cout << "Input the left [Y|N] :";
			char choose = ' ';
			cin >> choose;
			if (choose == 'y' || choose == 'Y') {
				createBTree(pRoot->pL, input, printData);
			}
		}
		if (pRoot->pR == NULL) {
			cout << "Current node: ";
			printData(pRoot);
			cout << "Input the right [Y|N] :";
			char choose = ' ';
			cin >> choose;
			if (choose == 'y'||choose=='Y') {
				createBTree(pRoot->pR, input, printData);
			}
		}

	}
}


void forEach(BNode *node, char *order, Enumerator func, BNode ** &params) {

	if (node == NULL)
		return;
	for (int i = 0; i<3; i++) {
		switch (order[i])
		{
		case 'L':
			forEach(node->pL, order, func, params);
			break;
		case 'R':
			forEach(node->pR, order, func, params);
			break;
		case 'N':
			func(node, params);
			break;
		}
	}
}

void forEach(BNode *node, char *order, Enumerator func) {
	BNode **params = NULL;
	forEach(node, order, func, params);
}