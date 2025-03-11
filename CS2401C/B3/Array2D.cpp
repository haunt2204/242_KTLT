#include <iostream>
using namespace std;

#define MAXR 20
#define MAXC 10

void init(int** &a, int &r, int &c) {
	a = NULL;
	r = c = 0;
}

void inputData(int &r, int &c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r <= 0 || c <= 0 || r > MAXR || c > MAXC) {
			cout << "Ngoai pham vi cho phep! Nhap lai!\n";
		}
	} while (r <= 0 || c <= 0 || r > MAXR || c > MAXC);
}

void inputArr(int** &a, int &r, int &c) {
	//Nhap dong cot
	inputData(r, c);
	//Xin cap phat theo so dong
	a = new int*[r];
	//Xin cap phat theo so cot
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}
	//Nhap tung phan tu cho mang 2D
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			//cin >> a[i][j];
			cin >> *(*(a + i) + j);//Ky phap do doi
		}
	}
}

void outputArr(const int* const* a, const int r, const int c) {
	if (a != NULL) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << *(*(a + i) + j) << "\t";
			}
			cout << endl;
		}
	}
	else
		cout << "Mang rong!\n";
}

int main() {
	//Khai bao mang 
	int **a;
	int r, c;

	//Khoi tao rong
	init(a, r, c);

	//Xin cap phat vung nho
	//Nhap tung phan tu
	inputArr(a, r, c);
	outputArr(a, r, c);
	//Thao tac, tinh toan

	//Giai phong vung nho (Cap phat sau, giai phong truoc)
	for (int i = 0; i < r; i++) {
		delete[]a[i];
	}
	delete[]a;
	return 0;
}