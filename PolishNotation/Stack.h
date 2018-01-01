
struct Stack {
	Op data[MAX_STACK];
	int top;
};

void init(Stack &stack) {
	stack.top = 0;
}

void push(Stack &stack, Op op) {
	if (stack.top < MAX_STACK) {
		stack.data[stack.top] = op;
		stack.top++;
	}
}

Op* getTop(Stack stack) {
	return stack.top > 0 ? &stack.data[stack.top-1] : NULL;
}

Op* pop(Stack &stack) {
	Op *result = getTop(stack);
	stack.top = stack.top > 0 ? stack.top - 1 : 0;
	return result;
}