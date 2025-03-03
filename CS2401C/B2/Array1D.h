#include <iostream>
#include <ctime>
using namespace std;

#define MAX 140

void inputNumElm(int &n) {
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
}

void inputArr(int *&a, int& n) {
	//Cho nguoi dung nhap so phan tu
	inputNumElm(n);
	//Xin cap phat vung nho
	a = new int[n];
	//Nhap tung phan tu
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void outputArr(const int *a, const int n) {
	//Xuat du lieu
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Tim kiem 1 phan tu tren mang 
int* find(const int *a, const int n, const int key) {
	int *res = NULL;

	//Sinh vien cai dat

	return res;
}

//Tim Min & Tim Max

bool isMin(int a, int b) {
	return a < b;
}

bool isMax(int a, int b) {
	return a > b;
}

int* findExtremum(int *a, const int n, bool compareFunc(int, int) = isMin) {
	if (a == NULL)
		return NULL;
	int pos = 0;

	for (int i = 1; i < n; i++) {
		if (compareFunc(a[i], a[pos]))
			pos = i;
	}

	return &a[pos];
}

//Tim phan tu co gia tri key

//Thao tac tinh toan tren mang
//Tinh tong toan bo va tinh tong co dieu kien
bool def(int n) {
	return true;
}

int sumArr(const int *a, const int n, bool func(int n) = def) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (func(*(a + i)))
			sum += *(a + i);
	}

	return sum;
}

//Sap xep cac phan tu trong mang
//Tang dan => giam dan
void sortArr(int *a, const int n, bool compareFunc(int, int) = isMin) {
	if (a != NULL) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (compareFunc(a[j], a[i]))
					swap(a[i], a[j]);
			}
		}
	}
}

//Dao nguoc mang
void reverseArr(int *a, int n) {
	if (a != NULL) {
		int *l = a;
		int *r = a + n - 1;
		while (l < r) {
			swap(*l++, *r--);
		}

	}
}
//Noi 2 mang tao thanh mang moi
int* concateArr(const int *a, const int n, const int *b, const int m, int &size) {
	int *res = NULL; int k = 0;
	size = n + m;

	//Xin cap phat vung nho
	res = new int[size];

	//Doi cac phan tu a sang res
	for (int i = 0; i < n; i++) {
		res[k++] = a[i];
	}

	//Doi cac phan tu b sang res
	for (int j = 0; j < m; j++) {
		res[k++] = b[j];
	}

	return res;
}
//Them tung phan tu vao mang hien co
void pushBackArr(int *&a, int &n, const int newElm) {
	if (a == NULL) {
		n = 1;
		a = new int[1];
		a[0] = newElm;
	}
	else {
		//Xin cap phat vung nho moi co n + 1 phan tu
		int *newArr = new int[n + 1];
		//Doi du lieu tu mang cu sang mang moi
		for (int i = 0; i < n; i++) {
			newArr[i] = a[i];
		}
		//Giai phong vung nho cu
		delete[]a;
		//Them phan tu moi vao mang moi
		newArr[n] = newElm;
		//Cho a tro den mang moi
		a = newArr;
		//Cap nhat so luong phan tu hien co trong mang
		n++;
	}
}

//Ham sinh mang ngau nhien
void genArrRand(int *&a, int &n) {
	//Cho nguoi dung nhap so phan tu
	inputNumElm(n);

	//Xin cap phat vung nho
	a = new int[n];

	//Sinh du lieu cho tung phan tu
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 100 + 1;
	}
}

//Kiem tra mang tang
bool isOrder(const int *a, const int n, bool compareFunc(int, int) = isMin) {
	if (n < 2)
		return true;
	for (int i = 1; i < n; i++) {
		if (compareFunc(a[i], a[i - 1]))
			return false;
	}

	return true;
}