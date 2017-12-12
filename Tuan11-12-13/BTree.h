
struct BNode {
	Data data;
	BNode *pLeft;
	BNode *pRight;
};

struct BTree {
	BNode *pRoot;
};

typedef Data(*InputMethod)();
typedef void(*OutputMethod)(Data);
typedef void(*Enumerator)(BNode *&input, BNode **&args);

void init(BTree &bTree) {
	bTree.pRoot = NULL;
}

BNode *createBNode(Data data) {
	BNode *newNode = new BNode;
	newNode->data = data;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}

void createBTree(BNode *&root, InputMethod inputFunc, OutputMethod outputFunc) {
	cout << "Current node: " << endl;
	outputFunc(root->data);
	cout << "Input data: " << endl;
	root = createBNode(inputFunc());
	cout << "Create Left <- [Y|N]: ";
	char choose = ' ';
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		createBTree(root->pLeft, inputFunc, outputFunc);
	}

	cout << "Create Right -> [Y|N]: ";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		createBTree(root->pRight, inputFunc, outputFunc);
	}
}

void forEach(BNode *&root, char *order, Enumerator func, BNode **&args) {

	if (root != NULL) {
		for (int i = 0; i < 3; i++) {
			switch (order[i]) {
			case 'L':
				forEach(root->pLeft, order, func, args);
				break;
			case 'R':
				forEach(root->pRight, order, func, args);
				break;
			case 'N':
				func(root, args);
				break;
			}
		}
	}
}

void forEach(BNode *&root, char *order, Enumerator func) {
	BNode **args = NULL;
	forEach(root, order, func, args);
}