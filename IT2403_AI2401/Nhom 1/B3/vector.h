//Mang 1 chieu cap phat dong
#include <iostream>
using namespace std;

#define MAX 100

void init(int*& a, int& n) {
	a = NULL;
	n = 0;
}

void inputNumElm(int& n) {
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
}

void inputArr(int*& a, int& n) {
	//Nhap so luong phan tu: n
	inputNumElm(n);
	//Xin cap phat vung nho
	a = new int[n];

	//Nhap tung phan tu
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Sinh mang ngau nhien
void genArrRand(int*& a, int& n) {
	//Nhap so phan tu
	inputNumElm(n);

	//Xin cap phat 
	a = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
}

void outputArr(const int* a, const int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Tinh tong cac phan tu trong mang (co dieu kien)

//Tim kiem
//Tim Max
bool isMax(int a, int b) {
	return a > b;
}

bool isMin(int a, int b) {
	return a < b;
}

int* findExtremum(int* a, const int n, bool compareFunc(int, int) = isMin) {
	if (a != NULL) {
		int pos = 0;
		for (int i = 1; i < n; i++) {
			if (compareFunc(a[i], a[pos]))
				pos = i;
		}
		return &a[pos];
	}
	return NULL;
}

//Them phan 01 phan tu moi vao mang hien co
void pushBackArr(int*& a, int& n, int newElm) {
	if (a == NULL) {
		n = 1;
		a = new int[n];
		a[0] = newElm;
	}
	else {
		int* newArr = new int[n + 1];
		for (int i = 0; i < n; i++) {
			newArr[i] = a[i];
		}

		newArr[n] = newElm;

		delete[]a;
		a = newArr;
		n++;
	}
}

//Tim Min
//Tim cac phan tu chua gia tri key
// a = {1,2,5,4,1}, key = 1, res = {0,4}
int* find(int* a, const int n, const int key, int &size) {
	int* res = NULL;// res = {0, 4}

	//Sinh vien cai dat
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			pushBackArr(res, size, i);
		}

	}

	return res;
}

//Thao tac sap xep: mac dinh sap tang dan => sang giam dan
void sortArr(int* a, const int n, bool compareFunc(int, int) = isMin) {
	//Interchange Sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareFunc(a[j], a[i]))
				swap(a[j], a[i]);
		}
	}
}
//Dao nguoc mang
void reverseArr(int* a, const int n) {
	int* l = a;
	int* r = (a + n - 1);

	while (l < r) {
		swap(*l++, *r--);
	}

}
//Noi 2 mang 
int* concateArr(const int* a, const int n, const int* b, const int m, int& size) {
	size = n + m;
	int* res = NULL;
	int k = 0;

	//Xin cap phat vung nho
	res = new int[size];

	//Chep du lieu tu a sang res
	for (int i = 0; i < n; i++) {
		res[k++] = a[i];
	}

	//Chep du lieu tu b sang res
	for (int j = 0; j < m; j++) {
		res[k++] = b[j];
	}

	return res;
}

#pragma once
