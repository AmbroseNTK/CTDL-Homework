#include<iostream>

int linearSearch(int *arr, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == key)
			return i;
	}
	return -1;
}
int binarySearch(int *arr, int n, int key) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (*(arr + m) == key)
			return m;
		if (key > *(arr + m))
			l = m + 1;
		else
			r = m - 1;
	}
}
int binarySearchRe(int *arr, int l, int r, int key) {
	int m = (l + r) / 2;
	if (*(arr + m) == key)
		return m;
	if (l >= r)
		return -1;
	if (key > *(arr + m))
		binarySearchRe(arr, m + 1, r, key);
	else
		binarySearchRe(arr, l, m - 1, key);
}