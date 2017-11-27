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
	add(queue, dA);
	add(queue, dB);
	add(queue, dC);
	cout << get(queue).a << "\t" << get(queue).a << "\t" << get(queue).a << endl;
	system("PAUSE");
}