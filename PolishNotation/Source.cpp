#include<iostream>

#define MAX_STACK 100

using namespace std;

struct Op {
	bool isOperator;
	char oTor;
	double oRand;
};

#include"Stack.h"

void createOp(Op &op, bool isOperator, char oTor, double oRand) {
	op.isOperator = isOperator;
	op.oTor = oTor;
	op.oRand = oRand;
}
void normalization(char *expr, Op *&result, int &length) {
	length = 0;
	result = new Op;
	int exprLen = strlen(expr);
	int numStart = -1;
	int numLen = 0;
	for (int i = 0; i < exprLen; i++) {
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '(' || expr[i] == ')') {
			if (numStart != -1 && numLen > 0) {
				char num[100];
				strncpy_s(num, exprLen, (expr + numStart), numLen);
				createOp(result[length], false, ' ', atof(num));
				numStart = -1;
				length++;
			}
			createOp(result[length], true, expr[i], 0);
			length++;
		}
		else
		{
			if (expr[i] != ' ') {
				if (numStart == -1) {
					numStart = i;
					numLen = 1;
				}
				else {
					numLen++;
				}
			}

		}
	}
	if (numStart != -1 && numLen > 0) {
		char num[100];
		strncpy_s(num, exprLen, (expr + numStart), numLen);
		createOp(result[length], false, ' ', atof(num));
		numStart = -1;
		length++;
	}
}

int getPriority(Op *oper) {
	if (oper == NULL)
		return 0;
	if (oper->isOperator) {
		if (oper->oTor == '*' || oper->oTor == '/')
			return 2;
		else
			return 1;
	}
	return 0;
}

void toPostfix(Op *expr, int length, Op *&result, int &resultLength) {
	Stack stack;
	init(stack);
	result = new Op;
	resultLength = 0;
	for (int i = 0; i < length; i++) {
		if (expr[i].isOperator == false) {
			result[resultLength] = expr[i];
			resultLength++;
		}
		else if (expr[i].oTor == ')') {
			while (stack.top > 0) {
				if (getTop(stack)->oTor != '(') {
					result[resultLength] = *pop(stack);
					resultLength++;
				}
				else {
					pop(stack);
					break;
				}
			}
		}
		else if (expr[i].oTor == '(') {
			push(stack, expr[i]);
		}
		else {
			if (getPriority(getTop(stack)) >= getPriority(expr + i) && getTop(stack)->oTor != '(') {
				result[resultLength] = *pop(stack);
				resultLength++;
				push(stack, expr[i]);
			}
			else {
				push(stack, expr[i]);
			}
		}
	}
	while (stack.top > 0) {
		result[resultLength] = *pop(stack);
		resultLength++;
	}
}

void printOpList(Op *list, int length) {
	for (int i = 0; i < length; i++) {
		if ((list + i) != NULL) {
			if (list[i].isOperator == true) {
				printf("%c ", list[i].oTor);
			}
			else {
				printf("%f ", list[i].oRand);
			}
		}
	}
}

double calc(Op *postfix, int length) {
	Stack opRand;
	init(opRand);

	for (int i = 0; i < length; i++) {

		if (postfix[i].isOperator == false) {
			push(opRand, postfix[i]);
		}
		else {
			if (postfix[i].oTor == '+') {
				Op operand;
				createOp(operand, false, ' ', pop(opRand)->oRand + pop(opRand)->oRand);
				push(opRand,operand);
			}
			else if (postfix[i].oTor == '-') {
				Op operand;
				createOp(operand, false, ' ', pop(opRand)->oRand - pop(opRand)->oRand);
				push(opRand, operand);
			}
			else if (postfix[i].oTor == '*') {
				Op operand;
				createOp(operand, false, ' ', pop(opRand)->oRand * pop(opRand)->oRand);
				push(opRand, operand);
			}
			else if (postfix[i].oTor == '/') {
				Op operand;
				createOp(operand, false, ' ', pop(opRand)->oRand / pop(opRand)->oRand);
				push(opRand, operand);
			}
		}
	}

	return pop(opRand)->oRand;
}

int main() {
	Op *opExpr = new Op;
	int opLen = 0;
	char expr[] = "(2 - 5)/(7 +6) - 2*(1+3.14)";
	normalization(expr, opExpr, opLen);
	cout << "Normalization: ";
	printOpList(opExpr, opLen);
	cout << endl;
	Op *posfix = new Op;
	int postLength = 0;
	toPostfix(opExpr, opLen, posfix, postLength);

	cout << "To Postfix: ";
	printOpList(posfix, postLength);
	cout << endl;
	cout << "Result: " << calc(posfix, postLength) << endl;
	return 0;
}