#include <iostream>
#include <ctime>
using namespace std;

#define MAXR 20
#define MAXC 10

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

void inputArr(int a[][MAXC], int& r, int& c) {
	inputData(r, c);

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

//Tao ra mot ma tran ngau nhien: 1-100
void genArr(int a[][MAXC], int& r, int& c) {
	inputData(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}
}

//Tinh tong gia tri tren dong
int tinhTongDong(const int a[][MAXC], const int r, const int c, const int vtDong) {
	int tong = 0;

	//vtDong = 0
	for (int j = 0; j < c; j++) {
		tong += a[vtDong][j];
	}

	return tong;
}

//Tinh tong gia tri tren cot
int tinhTongCot(const int a[][MAXC], const int r, const int c, const int vtCot) {
	int tong = 0;

	for (int i = 0; i < r; i++) {
		tong += a[i][vtCot];
	}

	return tong;
}

//Tinh toan tren 2 ma tran
void tinh2MaTran(const int a[][MAXC], const int b[][MAXC], int res[][MAXC], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
}

int main() {
	//Khai bao
	int a[MAXR][MAXC];
	int rA, cA;

	int b[MAXR][MAXC];
	int rB, cB;

	int res[MAXR][MAXC];
	int r, c;

	srand(time(NULL));

	//Thuc hien tinh A + B: 
	cout << "Tao ma tran A:\n";
	genArr(a, rA, cA);

	cout << "Tao ma tran B:\n";
	genArr(b, rB, cB);

	cout << "Ma tran A:\n";
	outputArr(a, rA, cA);

	cout << "Ma tran B:\n";
	outputArr(b, rB, cB);

	if (rA == rB&&cA == cB) {
		r = rA;
		c = cA;
		tinh2MaTran(a, b, res, r, c);
		cout << "Ket qua A+B:\n";
		outputArr(res, r, c);
		//Tai su dung
		//Hieu suat: tranh lap code, de mo rong
	}
	else
		cout << "2 Ma tran khong cung kich thuoc!\n";

	////Thao tac nhap, xuat mang 2 chieu
	////inputArr(a, r, c);
	//genArr(a, r, c);
	//outputArr(a, r, c);

	////Tinh toan
	//int vtDong;
	//cout << "Nhap dong can tinh: ";
	//cin >> vtDong;

	//cout << tinhTongDong(a, r, c, vtDong-1) << endl;

	return 0;
}