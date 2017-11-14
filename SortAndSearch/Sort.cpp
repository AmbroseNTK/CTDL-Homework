#include"Sort.h"

bool increase(int n1, int n2) {
	return n1 > n2;
}
bool decrease(int n1, int n2) {
	return n1 < n2;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void interchangeSort(int *arr, int n, SortType func) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (func(*(arr + i), *(arr + j)))
				swap(*(arr + i), *(arr + j));
		}
	}
}
void bubbleSort(int *arr, int n, SortType func) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (func(*(arr + i), *(arr + j)))
				swap(*(arr + i), *(arr + j));
		}
	}
}
void selectionSort(int *arr, int n, SortType func) {
	for (int i = 0; i < n - 1; i++) {
		int pos = i + 1;
		for (int j = i + 1; j < n; j++) {
			if (func(*(arr + pos), *(arr + j)))
				pos = j;
		}
		if (pos != i)
			swap(*(arr + i), *(arr + pos));
	}
}
void insertionSort(int *arr, int n, SortType func) {
	int j = 0;
	int key = 0;
	for (int i = 1; i < n; i++) {
		key = *(arr + i);
		for (j = i - 1; j >= 0 && !func(key, arr[j]); j--)
			*(arr + j + 1) = *(arr + j);
		*(arr + j + 1) = key;
	}
}
