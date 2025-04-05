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
	//Basic case
	if (n <= 0)
		return INT_MIN;

	if (n == 1)
		return a[0];

	//General case
	int max = findMax(a, n - 1);
	if (a[n - 1] > max)
		return a[n - 1];
	return max;
}

int main() {
	int a[] = { 9,5,7,1,6,8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << "Tong mang: " << tongArr(a, n) << endl;
	cout << "Tim max: " << findMax(a, n) << endl;

	return 0;
}