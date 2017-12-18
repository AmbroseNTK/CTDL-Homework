
struct BNode {
	Data data;
	BNode *pLeft;
	BNode *pRight;
};

struct BTree {
	BNode *pRoot;
};

typedef Data(*InputMethod)();
typedef void(*OutputMethod)(Data,int);
typedef void(*Enumerator)(BNode *&input, BNode **&args);
typedef int(*Comparison)(Data, Data);

#define EQUAL 0
#define NOT_EQUAL 1

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
	
	cout << "Input data: " << endl;
	root = createBNode(inputFunc());
	
	cout << "Current node: " << endl;
	if (root != NULL)
		outputFunc(root->data, 0);
	cout << "Create Left <- [Y|N]: ";
	char choose = ' ';
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		createBTree(root->pLeft, inputFunc, outputFunc);
	}

	cout << "Current node: " << endl;
	if (root != NULL)
		outputFunc(root->data, 0);
	cout << "Create Right -> [Y|N]: ";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		createBTree(root->pRight, inputFunc, outputFunc);
	}
}

void printTree(BNode * root, int depth, OutputMethod func) {
	if (root != NULL) {
		printTree(root->pLeft, depth + 1,func);
		func(root->data, depth*3);
		printTree(root->pRight, depth + 1,func);
	}
}

void search(BNode *root, Data key, Comparison compFunc, BNode *&result) {
	if (root != NULL) {
		if (compFunc(root->data, key) == EQUAL) {
			result = root;
			return;
		}
	}
	else
	{
		result = NULL;
	}
}

void forEach(BNode *&root, char *order, Enumerator func, BNode **&args) {

	if (root != NULL) {
		int len = strlen(order);
		for (int i = 0; i < len; i++) {
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