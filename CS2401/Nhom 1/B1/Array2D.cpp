#include <iostream>
#include <ctime>
using namespace std;

const int MAXR = 10;
const int MAXC = 5;

void inputData(int& r, int& c) {
	//Nhap so dong, so cot
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;

		if (r <= 0 || c <= 0 || r > MAXR || c > MAXC)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
	} while (r <= 0 || c <= 0 || r > MAXR || c > MAXC);
}

void inputArr(int a[][MAXC], int& r, int& c) {
	//Nhap so dong, so cot
	inputData(r, c);

	//Nhap gia tri tung phan tu cho mang 2 chieu
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void outputArr(const int a[][MAXC], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void sinhMangNN(int a[][MAXC], int& r, int& c) {
	//Nhap so dong, so cot
	inputData(r, c);

	//Nhap gia tri tung phan tu cho mang 2 chieu
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 50 + 1;
		}
	}
}

//Tinh tong dong bat ky
int tinhTongDong(const int a[][MAXC], const int r, const int c, const int vtDong) {
	int tong = 0;

	for (int j = 0; j < c; j++) {
		tong += a[vtDong][j];
	}

	return tong;
}
//Tinh tong cot bat ky
int tinhTongCot(const int a[][MAXC], const int r, const int c, const int vtCot) {
	int tong = 0;

	for (int i = 0; i < r; i++) {
		tong += a[i][vtCot];
	}

	return tong;
}

void tinh2MaTran(const int a[][MAXC], const int b[][MAXC], int res[][MAXC], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
}


int main() {
	////Khai bao mang 2 chieu
	//int a[MAXR][MAXC], r, c;

	////Nhap mang 2 chieu
	////inputArr(a, r, c);
	//srand(time(NULL));
	//sinhMangNN(a, r, c);
	////Xuat mang 2 chieu
	//outputArr(a, r, c);
	////Tinh tong dong
	//cout << tinhTongDong(a, r, c, 1) <<endl;

	int a[MAXR][MAXC], rA, cA;
	int b[MAXR][MAXC], rB, cB;
	int res[MAXR][MAXC], r, c;

	srand(time(NULL));

	cout << "Nhap ma tran A:\n";
	sinhMangNN(a, rA, cA);
	cout << "Nhap ma tran B:\n";
	sinhMangNN(b, rB, cB);

	cout << "Ma tran A:\n";
	outputArr(a, rA, cA);

	cout << "Ma tran B:\n";
	outputArr(b, rB, cB);

	if (rA == rB && cA == cB) {
		r = rA;
		c = cA;
		//Tinh tong: A+B
		cout << "Ma tran ket qua A+B:\n";
		tinh2MaTran(a, b, res, rA, cA);
		outputArr(res, r, c);
		//A-B

		//A*B

	}
	else
		cout << "Hai ma tran khong cung kich thuoc!\n";

	return 0;
}