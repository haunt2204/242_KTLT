#include <iostream>
using namespace std;

int tongArr(int a[], int n, int sum = 0) {
	//Basic case
	if (n <= 0)
		return sum;

	//General case
	return tongArr(a, n - 1, a[n - 1] + sum);
}

int findMax(int a[], int n) {
	if (n < 1)
		return INT_MIN;

	if (n == 1)
		return a[0];

	int max = findMax(a, n - 1);
	if (max > a[n - 1])
		return max;
	return a[n - 1];
}

int main() {
	int a[] = { 5,4,8,6,7 };
	int n = sizeof(a)/sizeof(a[0]);

	cout << "Tong mang: " << tongArr(a, n) << endl;
	cout << "Tim max: " << findMax(a, n) << endl;

	return 0;
}