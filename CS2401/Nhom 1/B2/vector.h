//Cap phat dong mang 1 chieu
#include <iostream>
using namespace std;

#define MAX 100

//Khoi tao rong
void init(int*& a, int& n) {
	a = NULL;
	n = 0;
}


void inputNumElm(int& n) {
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
}

//Nhap mang
void inputArr(int*& a, int& n) {
	//Nhap so luong phan tu 
	inputNumElm(n);
	//Xin cap phat vung nho
	a = new int[n];

	//Nhap tung phan tu cho mang
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Sinh mang ngau nhien
void genArrRand(int*& a, int& n) {
	//Nhap so luong phan tu 
	inputNumElm(n);

	//Xin cap phat vung nho
	a = new int[n];

	//Nhap tung phan tu cho mang
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
}

//Xuat mang
void outputArr(const int* a, const int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
	else
		cout << "Mang rong!\n";
}

//Tinh tong cac phan tu trong mang (co dieu kien)

//Tim kiem
////Tim max
////Tim min
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

////Tim phan tu chua gia tri key
int* find(int* a, const int n, const int key) {
	//1 2 2 3 5 2
	int* res = NULL;
	//Sinh vien cai dat theo huong dan
	return res;
}

//Sap xep mang: mac dinh tang dan (co the linh hoat chuyen sang giam dan)
void sort(int* a, const int n, bool func(int, int)) {
	if (a != NULL) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (func(a[j], a[i]))
					swap(a[i], a[j]);
			}
		}
	}
}

//Noi 2 mang
int* concateArr(const int* a, const int n, const int* b, const int m, int& size) {
	int* c = NULL; int k = 0;
	size = n + m;

	//Xin cap phat mang moi
	c = new int[size];

	//Doi du lieu tu a sang c
	for (int i = 0; i < n; i++) {
		c[k++] = a[i];
	}

	//Doi du lieu tu b sang c
	for (int j = 0; j < m; j++) {
		c[k++] = b[j];
	}

	return c;
}

//Dao nguoc mang
void reverseArr(int* a, const int n) {
	if (a != NULL) {
		int* l = a;
		int* r = (a + n - 1);

		while (l < r) {
			swap(*l++, *r--);
		}
	}
}

//Them 1 phan tu vao trong mang hien co
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
