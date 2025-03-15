//Mang 1D cap phat dong
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
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
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
		cin >> *(a + i);
	}
}

//Thao tac sinh mang ngau nhien
void genArrRand(int*& a, int& n) {
	//Nhap so luong phan tu
	inputNumElm(n);

	//Xin cap phat
	a = new int[n];

	//Nhap tung phan tu 
	for (int i = 0; i < n; i++) {
		*(a + i) = rand() % 100 + 1;
	}
}

void outputArr(const int* a, const int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << "\t";
		}
		cout << endl;
	}
	else
		cout << "Mang rong!\n";
}

//Thao tac tinh tong mang (co dieu kien)

//Thao tac tim kiem 
////Tim max
bool isMax(int a, int b) {
	return a > b;
}

bool isMin(int a, int b) {
	return a < b;
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
////Tim min
////Tim cac phan tu chua gia tri key

//Thao tac sap xep: mac dinh sap tang => sap giam dan
void sort(int* a, const int n, bool compareFunc(int, int) = isMin) {
	//Interchange Sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareFunc(a[j], a[i])) {
				swap(a[i], a[j]);
			}
		}
	}
}
//Thao tac dao nguoc mang
void reverseArr(int* a, const int n) {
	if (a == NULL)
		return;

	int* l = a;
	int* r = a + n - 1;
	while (l < r) {
		swap(*l++, *r--);
	}

}
//Thao tac noi 2 mang tao thanh mang moi
int* concateArr(int* a, int n, int* b, int m, int& size) {
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

//Thao tac them 1 phan tu moi vao mang hien co
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

		newArr[n++] = newElm;
		delete[]a;//Giai phong vung nho cu
		a = newArr;
	}
}
//Thao tac kiem tra mang co thu tu hay khong (tang hoac giam)
bool isOrder(const int* a, const int n, bool compareFunc(int, int) = isMin) {
	for (int i = 0; i < n - 1; i++) {
		if (compareFunc(a[i + 1], a[i]))
			return false;
	}
	return true;
}
