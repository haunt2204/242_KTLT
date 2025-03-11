//Mang 1 chieu cap phat dong
#include <iostream>
using namespace std;

#define MAX 100

void init(int*& a, int& n) {
	a = NULL;
	n = 0;
}

void inputNumElm(int& n) {
	//Nhap so luong phan tu
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
}

void inputArr(int*& a, int& n) {
	//Nhap so luong phan tu
	inputNumElm(n);
	//Xin cap phat
	a = new int[n];
	//Nhap tung phan tu
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Sinh mang ngau nhien
void genArrRand(int*& a, int& n) {
	//Nhap so luong phan tu
	inputNumElm(n);
	//Xin cap phat
	a = new int[n];
	//Nhap tung phan tu
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
}

void outputArr(const int* a, const int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "Danh sach rong!\n";
}

//Tinh tong co dieu kien

//Thao tac tim kiem
//Tim Max
//Tim Min
bool isMin(int a, int b) {
	return a < b;
}

bool isMax(int a, int b) {
	return a > b;
}

int* findExtremum(int* a, const int n, bool compareFunc(int, int) = isMin) {
	if (a == NULL)
		return NULL;
	int pos = 0;
	for (int i = 1; i < n; i++) {
		if (compareFunc(a[i], a[pos]))
			pos = i;
	}

	return &a[pos];
}

//Tim cac phan tu co chua gia tri key


//Thao tac sap xep mang: mac dinh sap tang dan => sang giam dan
void sort(int* a, const int n, bool compareFunc(int, int) = isMin) {
	//Interchange sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareFunc(a[j], a[i]))
				swap(a[i], a[j]);
		}
	}
}
//Dao nguoc mang
void reverseArr(int* a, const int n) {
	if (a != NULL) {
		int* l = a;
		int* r = a + n - 1;
		while (l < r) {
			swap(*l++, *r--);
		}
	}
}
//Noi 2 mang
int* concateArr(const int* a, const int n, const int* b, const int m, int& size) {
	size = n + m;
	int* res = NULL;
	int k = 0;

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

//Them phan tu moi vao mang hien co
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

		//Them phan tu moi vao mang
		newArr[n] = newElm;
		n++;

		//Giai phong mang cu
		delete[]a;

		//Dieu chinh a tro toi mang moi
		a = newArr;
	}
}

//Kiem tra mang co thu tu hay khong
bool isOrder(const int* a, int n, bool compareFunc(int, int) = isMin) {
	if (a != NULL) {
		for (int i = 0; i < n - 1; i++) {
			if (compareFunc(a[i], a[i + 1]))
				return false;
		}
		return true;
	}
	return false;
}
