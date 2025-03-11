#include <iostream>
#include <iomanip>
using namespace std;

#define MAXR 20
#define MAXC 10

void inputData(int& r, int& c) {
	do {
		cout << "Nhap so dong: ";
		cin >> r;
		cout << "Nhap so cot: ";
		cin >> c;
		if (r <= 0 || c <= 0 || r > MAXR || c > MAXC)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
	} while (r <= 0 || c <= 0 || r > MAXR || c > MAXC);
}

void inputArr2D(int a[][MAXC], int& r, int& c) {
	
	inputData(r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void outputArr2D(const int a[][MAXC], const int r, const int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << setw(5) << a[i][j] << " ";
		}
		cout << endl;
	}
}

//Sinh mang ngau nhien
void genArr2D(int a[][MAXC], int& r, int& c) {
	inputData(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 100 + 1;//1-100
		}
	}
}

//Tinh tong dong
int tinhTongDong(const int a[][MAXC], const int r, const int c, const int vtDong) {
	int tong = 0;

	for (int j = 0; j < c; j++) {
		tong += a[vtDong][j];
	}

	return tong;
}

//Tinh tong cot
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
	//Khai bao
	int a[MAXR][MAXC];
	int rA, cA;

	int b[MAXR][MAXC];
	int rB, cB;

	int res[MAXR][MAXC];
	int r, c;

	srand(time(NULL));

	//Nhap du lieu
	cout << "Nhap ma tran A: ";
	genArr2D(a, rA, cA);
	cout << "Nhap ma tran B: ";
	genArr2D(b, rB, cB);
	
	//Xuat du lieu
	cout << "Ma tran A:\n";
	outputArr2D(a, rA, cA);

	cout << "Ma tran B:\n";
	outputArr2D(b, rB, cB);

	//Tinh toan tren 2 Ma tran
	if (rA == rB && cA == cB) {
		r = rA;
		c = cA;
		tinh2MaTran(a, b, res, r, c);
		cout << "Ma tran A+B:\n";
		outputArr2D(res, r, c);
	}
	else
		cout << "Hai ma tran khong cung kich thuoc!\n";

	////Thao tac nhap mang
	////inputArr2D(a, r, c);
	//genArr2D(a, r, c);//1-100
	////Thao tac xuat mang
	//outputArr2D(a, r, c);

	////Tinh tong dong
	//int vtDong;
	//cout << "Nhap vi tri dong can tinh: ";
	//cin >> vtDong;//Thu tu cua dong trong
	//cout << tinhTongDong(a, r, c, vtDong-1) << endl;

	return 0;
}