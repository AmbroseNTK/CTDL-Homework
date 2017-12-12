
struct Stack {
	Data data[MAX_N];
	int top = 0;
};

void init(Stack &stack) {
	stack.top = 0;
}

void push(Data data, Stack &stack) {
	if (stack.top < MAX_N) {
		stack.data[stack.top++] = data;
	}
}

Data pop(Stack &stack) {
	if (stack.top > 0) {
		return stack.data[--stack.top];
	}
	return emptyData;
}

Data getTop(Stack stack) {
	if (stack.top > 0) {
		return stack.data[stack.top - 1];
	}
	return emptyData;
}

