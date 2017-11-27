#pragma once

struct Stack {
	Data data[S_MAX];
	int top;
};

void init(Stack &stack) {
	stack.top = 0;
}
bool push(Stack &s, Data data) {
	if (s.top < S_MAX) {
		s.data[s.top] = data;
		s.top++;
		return true;
	}
	return false;
}

Data pop(Stack &s) {
	s.top--;
	return s.data[s.top];
}

Data getTop(Stack s) {
	return s.data[s.top - 1];
}