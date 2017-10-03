#include<iostream>
#include<conio.h>

struct sa {
	int a;
}s;
void func(struct sa) {
	s.a = 10;
	printf("%d", s.a);
}
void main() {
	func(s);
	printf("%d", s.a);
	_getch();
}