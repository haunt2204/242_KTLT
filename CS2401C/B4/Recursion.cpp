#include <iostream>
using namespace std;

int tinhTongArr(int a[], int n, int left=0, int sum=0) {
	//Basic case
	if (left==n)
		return sum;
	//General case
	return tinhTongArr(a, n, left+1, sum+a[left]);
}

//Tim gia tri lon nhat trong mang bang de quy
int findMax(int a[], int n, int l = 0) {
	//Basic case
	if (l == n - 1)
		return a[l];

	//General case
	int max = findMax(a, n, l + 1);
	if (a[l] > max)
		return a[l];
	else
		return max;
}

int main() {
	int a[] = { 4,5,7,1,6,3,9 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << tinhTongArr(a, n) << endl;
	cout << "Max: " << findMax(a, n) << endl;

	return 0;
}