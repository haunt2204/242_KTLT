#include <iostream>
using namespace std;

int tinhTongArr(int a[], int n, int sum = 0) {
	//Basic case
	if (n <= 0)
		return sum;
	//General case
	return tinhTongArr(a, n - 1, a[n - 1] + sum);
}

int findMax(int a[], int n) {
	//Basic
	if (n <= 0)
		return INT_MIN;

	if (n == 1)
		return a[0];
	//General
	int max = findMax(a, n - 1);
	if (a[n - 1] > max)
		return a[n - 1];

	return max;
}

int main() {
	int a[] = { 4,6,2,8,1,9,5 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << "Tinh tong mang: " << tinhTongArr(a, n) << endl;
	cout << "Tim max: " << findMax(a, n) << endl;

	return 0;
}