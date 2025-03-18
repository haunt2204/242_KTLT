#include <iostream>
using namespace std;

#define MAXR 20
#define MAXC 10

void init(int **&a, int &r, int &c) {
	a = NULL;
	r = c = 0;
}

void inputData(int& r, int& c) {
	//Nhap dong, cot
	do {
		cout << "Nhap dong: ";
		cin >> r;
		cout << "Nhap cot: ";
		cin >> c;
		if (r <= 0 || c <= 0 || r > MAXR || c > MAXC)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
	} while (r <= 0 || c <= 0 || r > MAXR || c > MAXC);
}

void inputArr(int**& a, int& r, int& c) {
	//Nhap dong, cot
	inputData(r, c);
	//Xin cap phat
	////Cap phat theo so dong
	a = new int*[r];
	////Cap phat theo so cot
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}
	//Nhap tung phan tu
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			//cin >> a[i][j];
			cin >> *(*(a+i) + j);
		}
	}
}

void outputArr(const int* const* a, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}

int main() {
	//Khai bao
	int** a;
	int r, c;

	//Khoi tao
	init(a, r, c);
	//Xin cap phat
	inputArr(a, r, c);
	outputArr(a, r, c);

	//Thao tac tren mang 2D

	//Giai phong vung nho
	for (int i = 0; i < r; i++) {
		delete []a[i];
	}

	delete[]a;
	return 0;
}