//Nguyen Tuan Kiet - 2162392
#include<iostream>
#include<conio.h>

using namespace std;

float T2(int n) {
	if (n == 1)
		return 1;
	return 1.0 / n + T2(n - 1);
}
int sumSeq(int n) {
	if (n == 1)
		return 1;
	return n + sumSeq(n - 1);
}
float T3(int n) {
	if (n == 1)
		return 1;
	return 1.0 / sumSeq(n) + T3(n - 1);
}
double powRecursion(float x, int n) {
	if (n == 1)
		return x;
	return x*powRecursion(x, n - 1);
}
long factor(int n) {
	if (n == 1)
		return 1;
	return n*factor(n - 1);
}
long S(int n) {
	if (n == 1)
		return 1;
	return factor(n) + S(n - 1);
}
long S(int x, int n) {
	if (n == 0)
		return 0;
	return powRecursion(x, 2 * (n - 1) + 1) + S(x, n - 1);
}
int countNum(int n) {
	if (n == 0)
		return 0;
	return 1 + countNum(n / 10);
}
int numRev(int n) {
	if (n == 0)
		return 0;
	return (n % 10)*pow(10, countNum(n) - 1) + numRev(n / 10);
}
int countDecimal(float n) {
	int m = n;
	if (m - n == 0)
		return 0;
	return 1 + countDecimal(n * 10);
}
int sumNum(int n) {
	if (n == 0)
		return 0;
	return n%10 + sumNum(n / 10);
}
int minNum(int n) {
	static int num = n % 10;
	if (n == 0)
		return num;

	if (n % 10 < num)
		num = n % 10;
	
	return minNum(n / 10);
}
bool numOdd(int n) {
	static bool odd = true;
	if (n == 0)
		return odd;

	if ((n % 10) % 2 == 0)
		odd &= false;

	return numOdd(n / 10);
}
void main() {
	cout << "Enter n: ";
	int n = 0;
	cin >> n;

	cout << "Enter x: ";
	int x = 0;
	cin >> x;

	cout << "Enter float m: ";
	float m = 0;
	cin >> m;

	cout << "T2(" << n << ") = " << T2(n) << endl
		<< "T3(" << n << ") = " << T3(n) << endl
		<< "Pow(" << x << ", " << n << ") = " << powRecursion(x, n) << endl
		<< "S(" << n << ") = " << S(n) << endl
		<< "S(" << x << ", " << n << ") = " << S(x, n) << endl
		<< "NumRev(" << n << ") = " << numRev(n) << endl
		<< "CountNum(" << n << ") = " << countNum(n) << endl
		<< "CountDecimal(" << m << ") = " << countDecimal(m) << endl
		<< "SumNum(" << n << ") = " << sumNum(n) << endl
		<< "MinNum(" << n << ") = " << minNum(n) << endl
		<< "NumOdd(" << n << ") = " << (numOdd(n) ? "Full Odd" : "Non-Odd") << endl;
	_getch();
}