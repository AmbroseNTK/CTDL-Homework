#include<iostream>
#include<Windows.h>

using namespace std;

void main() {
	//Set width and height for 2-D array
	int width = 4;
	int height = 2;

	//Init a new 2-D array (A)
	int **A = new int*[height];
	for (int i = 0; i < height; i++) {
		*(A + i) = new int[width];
	}

	//Init a new 2-D array (A)
	int **B = new int*[height];
	for (int i = 0; i < height; i++) {
		*(B + i) = new int[width];
	}

	//Init max array
	int *k = new int[height];

	//Input from keyboard
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << "A(" << i<<" , "<< j << ") = ";
			int input;
			cin >> input;
			//Looking for maximum (k)
			if (input > k[i])
				k[i] = input;
			A[i][j] = input;
		}
		for (int j = 0; j < width; j++) {
			B[i][j] = A[i][j] * k[i];
		}
	}
	
	//Show result
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << B[i][j] << "\t";
		}
		cout << "\tK=" << k[i] << endl;
	}
	system("PAUSE");
}