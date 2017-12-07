#include<iostream>
#include<Windows.h>

#define S_MAX 1000

using namespace std;

struct Data
{
	int a;
};

#include"Stack.h"
#include"Queue.h"

void main() {
	Queue queue;
	init(queue);
	Data dA, dB, dC;
	dA.a = 1;
	dB.a = 2;
	dC.a = 3;
	push(queue, dA);
	push(queue, dB);
	push(queue, dC);
	cout << pop(queue).a << "\t" << pop(queue).a << "\t" << pop(queue).a << endl;
	system("PAUSE");
}