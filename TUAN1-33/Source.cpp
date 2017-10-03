//Nguyen Tuan Kiet - 2162392
#include<iostream>
#include<conio.h>

struct Point {
	int x;
	int y;
};
void addPoints(Point *listPoint, int n) {
	for (int i = 0; i < n; i++) {
		printf("Enter point #%d:\n", i);
		printf("\tx = ");
		scanf_s("%d", &listPoint[i].x);
		printf("\ty = ");
		scanf_s("%d", &listPoint[i].y);
	}
}
void printPoints(Point *listPoint, int n) {
	for (int i = 0; i < n; i++) {
		printf("Point #%d: (%d, %d)\n", i, listPoint[i].x, listPoint[i].y);
	}
}
int countPositive(Point *listPoint, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (listPoint[i].x > 0)
			result++;
	}
	return result;
}
bool isDuplicated(Point *listPoint, int current) {
	for (int i = 0; i < current; i++)
		if (listPoint[i].x == listPoint[current].x && listPoint[i].y == listPoint[current].y)
			return true;
	return false;
}
int countDifferent(Point *listPoint, int n) {
	int result = n;
	for (int i = 0; i < n; i++) {
		if (isDuplicated(listPoint, i))
			result--;
	}
	return result;
}
Point maxXPoint(Point *listPoint, int n) {
	Point max = listPoint[0];
	for (int i = 1; i < n; i++)
		if (listPoint[i].x > max.x)
			max = listPoint[i];
	return max;
}
Point minXPoint(Point *listPoint, int n) {
	Point min = listPoint[0];
	for (int i = 1; i < n; i++)
		if (listPoint[i].x < min.x)
			min = listPoint[i];
	return min;
}
float distanceOf(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
Point minDistanceTo(Point *listPoint, Point target, int n) {
	Point result = listPoint[0];
	float  min = distanceOf(listPoint[0], target);
	for (int i = 1; i < n; i++) {
		float currentDistance = distanceOf(listPoint[i], target);
		if (currentDistance < min) {
			result = listPoint[i];
			min = currentDistance;
		}
	}
	return result;
}
void main() {
	int n;
	printf("Enter n:");
	scanf_s("%d", &n);
	Point *listPoint = new Point[n];
	addPoints(listPoint, n);
	printPoints(listPoint, n);
	printf("\nNumber of positive x point: %d", countPositive(listPoint, n));
	printf("\nNumber of different points: %d", countDifferent(listPoint, n));
	Point maxP = maxXPoint(listPoint, n);
	Point minP = minXPoint(listPoint, n);
	printf("\nMax point: (%d, %d)", maxP.x, maxP.y);
	printf("\nMin point: (%d, %d)", minP.x, minP.y);
	Point root = { 0,0 };
	Point minDist = minDistanceTo(listPoint, root, n);
	printf("\nThe point nearest root: (%d, %d)", minDist.x, minDist.y);
	_getch();
}