#pragma once
#ifndef SORT_H
#define SORT_H

typedef bool(*SortType)(int, int);

bool increase(int, int);
bool decrease(int, int);
void interchangeSort(int *arr, int n, SortType func);
void bubbleSort(int *arr, int n, SortType func);
void selectionSort(int *arr, int n, SortType func);
void insertionSort(int *arr, int n, SortType func);

#endif // !SORT_H
