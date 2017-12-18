
struct BNode {
	Data data;
	BNode *pLeft;
	BNode *pRight;
};

struct BST {
	BNode *pRoot;
};

#define GREATER_THAN 1
#define EQUAL 0
#define LESS_THAN -1

typedef Data(*InputMethod)();
typedef void(*OutputMethod)(Data);
typedef int(*Comparison)(Data, Data);
typedef void(*Enumeration)(BNode*, BNode**&);

void init(BST &bst) {
	bst.pRoot = NULL;
}

BNode* createNode(Data data) {
	BNode *node = new BNode;
	node->data = data;
	node->pLeft = node->pRight = NULL;
	return node;
}

void createBST(BNode *&root, BNode *newNode, Comparison comFunc) {
	
	if (root == NULL) {
		root = newNode;
	}
	else {
		switch (comFunc(root->data,newNode->data))
		{
		case GREATER_THAN:
			createBST(root->pRight, newNode, comFunc);
			break;
		case LESS_THAN:
			createBST(root->pLeft, newNode, comFunc);
			break;
		}
	}
	
}


void createBST(BST &tree, InputMethod inFunc, Comparison comFunc) {
	do {
		BNode *newNode = createNode(inFunc());
		createBST(tree.pRoot, newNode, comFunc);
		cout << "Continue [Y|N]? ";
		char choose = ' ';
		cin >> choose;
		if (choose == 'n' || choose == 'N')
			break;
	} while (true);
}

BNode* search(BNode *root, Data key, Comparison comFunc) {
	BNode* temp = root;
	while (temp != NULL) {
		switch (comFunc(temp->data, key)) {
		case EQUAL:
			return temp;
			break;
		case GREATER_THAN:
			temp = temp->pRight;
			break;
		case LESS_THAN:
			temp = temp->pLeft;
			break;
		}
	}
	return NULL;
}

void forEach(BNode *root, char *order, Enumeration func, BNode **&args) {
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

void forEach(BNode *root, char *order, Enumeration func) {
	BNode **args = NULL;
	forEach(root, order, func, args);
}

void maxNode(BNode *input, BNode **&args) {
	if (input != NULL && input->pRight == NULL)
		args[0] = input;
	else if (input == NULL)
		args[0] = NULL;
	
}

void minNode(BNode *input, BNode **&args) {
	if (input != NULL &&input->pLeft == NULL)
		args[0] = input;
	else if (input == NULL)
		args[0] = NULL;

}

BNode* findMax(BNode *root) {
	BNode **result = NULL;
	forEach(root, "R", maxNode, result);
	return result[0];
}

BNode* findMin(BNode *root) {
	BNode **result = NULL;
	forEach(root, "L", minNode,result);
	return result[0];
}

void deleteNode(BNode *&root, BNode *deletion, Comparison comFunc) {
	
	if (root != NULL) {
		switch (comFunc(root->data, deletion->data)) {
		case EQUAL:
			if (root->pLeft == root->pRight == NULL) {
				root = NULL;
			}
			else if (root->pLeft == NULL) {
				root = root->pRight;
			}
			else if (root->pRight == NULL) {
				root = root->pLeft;
			}
			else {
				BNode *dummy = findMin(root->pRight);
				root->data = dummy->data;
				deleteNode(root->pLeft, dummy, comFunc);
			}
			break;
		case GREATER_THAN:
			deleteNode(root->pRight, deletion, comFunc);
			break;
		case LESS_THAN:
			deleteNode(root->pLeft, deletion, comFunc);
			break;
		}
	}
}