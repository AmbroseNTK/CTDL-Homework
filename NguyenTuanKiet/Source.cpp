//Nguyen Tuan Kiet - 2162392
#include<iostream>
#include<conio.h>

struct Point {
	int x;
	int y;
};
struct Triangle {
	Point p1;
	Point p2;
	Point p3;
};
void addPoint(Point &p) {
	printf("x = ");
	scanf_s("%d", &p.x);
	printf("y = ");
	scanf_s("%d", &p.y);
}
void printPoint(Point p) {
	printf("\n(%d, %d)", p.x, p.y);
}
float distanceOf(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
Point reflect(Point source) {
	Point result = { -1 * source.x,-1 * source.y };
	return result;
}
void checkPart(Point p) {
	if (p.x*p.y > 0)
		if (p.x < 0)
			printf("Point is in Part III");
		else
			printf("Point is in Part I");
	else
		if (p.x < 0)
			printf("Point is in Part II");
		else
			printf("Point is in Part IV");
}
void addTriangle(Triangle &triangle) {
	printf("\nEnter the first point:\n");
	addPoint(triangle.p1);
	printf("Enter the second point:\n");
	addPoint(triangle.p2);
	printf("Enter the third point:\n");
	addPoint(triangle.p3);
}
void printTriangle(Triangle triangle) {
	printf("Triangle has three points: \n");
	printPoint(triangle.p1);
	printPoint(triangle.p2);
	printPoint(triangle.p3);
}
float calcPerimeter(Triangle triangle) {
	return distanceOf(triangle.p1, triangle.p2) + distanceOf(triangle.p2, triangle.p3) + distanceOf(triangle.p3, triangle.p1);
}
float calcSize(Triangle triangle) {
	//Heron's formula
	float semiPerimeter = calcPerimeter(triangle)*0.5;
	return sqrt(semiPerimeter*
		(semiPerimeter - distanceOf(triangle.p1, triangle.p2))*
		(semiPerimeter - distanceOf(triangle.p2, triangle.p3))*
		(semiPerimeter - distanceOf(triangle.p3, triangle.p1)));
}
void main() {
	Point p1,p2;
	printf("Add point #1\n");
	addPoint(p1);
	printf("Add point #2\n");
	addPoint(p2);

	printPoint(p1);
	printPoint(p2);

	printf("\nThe distance between point #1 and point #2 = %f", distanceOf(p1, p2));

	Point refPoint = reflect(p1);
	printf("\nThe reflect point of (%d, %d) via O(0, 0) is (%d, %d)\n", p1.x, p1.y, refPoint.x, refPoint.y);
	checkPart(p1);

	Triangle triangle;
	addTriangle(triangle);
	printTriangle(triangle);
	printf("\nPerimeter of triangle C = %f", calcPerimeter(triangle));
	printf("\nSize of triangle S = %f", calcSize(triangle));
	_getch();
}