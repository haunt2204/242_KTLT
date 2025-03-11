#include <iostream>
using namespace std;

#define MAXR 20
#define MAXC 10

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

void inputArr(int a[][MAXC], int& r, int& c) {
	//Nhap dong, cot
	inputData(r, c);

	//Nhap tung phan tu trong mang 2 chieu
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
			cout << a[i][j] << "\t";
		}

		cout << endl;
	}
}

//Viet chuong trinh sinh ma tran ngau nhien
void genArr(int a[][MAXC], int& r, int& c) {
	//Nhap dong, cot
	inputData(r, c);

	//Nhap tung phan tu trong mang 2 chieu
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 100 + 1;
		}
	}
}

//Tinh tong 1 dong bat ky
int tinhTongDong(const int a[][MAXC], const int r, const int c, const int vtDong) {
	int tong = 0;

	for (int j = 0; j < c; j++) {
		tong += a[vtDong][j];
	}

	return tong;
}

//Tinh tong 1 cot bat ky
int tinhTongCot(const int a[][MAXC], const int r, const int c, const int vtCot) {
	int tong = 0;

	for (int i = 0; i < r; i++) {
		tong += a[i][vtCot];
	}

	return tong;
}

int tinh2MaTran(const int a[][MAXC], const int b[][MAXC], int res[][MAXC], const int r, const int c) {
	int tong = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}

	return tong;
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

	cout << "Nhap ma tran A:\n";
	genArr(a, rA, cA);

	cout << "Nhap ma tran B:\n";
	genArr(b, rB, cB);

	cout << "Ma tran A:\n";
	outputArr(a, rA, cA);

	cout << "Ma tran B:\n";
	outputArr(b, rB, cB);

	if (rA == rB && cA == cB) {
		r = rA;
		c = cA;
		tinh2MaTran(a, b, res, r, c);
		cout << "Ma tran A+B:\n";
		outputArr(res, r, c);
	}
	else
		cout << "Hai ma tran khong cung kich thuoc!\n";

	////Thao tac tren mang 2 chieu
	////Nhap/xuat
	////inputArr(a, r, c);
	//genArr(a, r, c);
	//outputArr(a, r, c);

	////Tinh tong dong
	//int vtDong;
	//cout << "Nhap vi tri dong can tinh: ";
	//cin >> vtDong;

	//cout << tinhTongDong(a, r, c, vtDong-1) << endl;

	return 0;
}