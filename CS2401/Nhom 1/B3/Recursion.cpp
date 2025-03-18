#include <iostream>
using namespace std;

//Tinh giai thua: n!= n*(n-1)!
//int tinhGT(int n) {
//	//Basic case
//	if (n == 0)
//		return 1;
//	//General case
//	return n * tinhGT(n - 1);
//}

int tinhGT(int n, int gt = 1) {
	//Basic case
	if (n == 0)
		return gt;
	//General case
	return tinhGT(n - 1, gt*n);
}

//Tinh S = 1 + 2 + ... + n
int tinhTong(int n, int tong = 0) {
	//Basic case
	if (n == 0)
		return tong;
	//General case
	return tinhTong(n - 1, n + tong);
}

//Tinh tong binh phuong
int tinhTongBP(int n, int tong = 0) {
	if (n == 0)
		return tong;

	return tinhTongBP(n - 1, n*n + tong);
}

double tinhTongThuong(int n, double tong = 0) {
	if (n <= 0)
		return tong;

	if (n % 2 == 0)
		return tinhTongThuong(n - 1, tong);

	return tinhTongThuong(n - 2, 1.0/n + tong);
}

int tinhTongGT(int n, int tong = 0) {
	//Basic case
	if (n == 0)
		return tong;
	//General case
	return tinhTong(n - 1, tinhGT(n) + tong);
}
//0,1,1,2,3,5
//Fn = Fn-1 + Fn-2
int tinhFibo(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return tinhFibo(n - 1) + tinhFibo(n - 2);
}

double tinhLuyThua(int x, int n, double res = 1) {
	if (n == 0)
		return res;

	if (n < 0) {
		if (x == 0)
			return -1;
		return tinhLuyThua(x, n + 1, 1.0 / x * res);
	}
		
	return tinhLuyThua(x, n - 1, x * res);
}

int demChuSo(int n, int dem = 0) {
	if (n == 0)
		return dem;

	return demChuSo(n / 10, dem + 1);
}

int tinhSDN(int n, int sdn = 0) {
	if (n == 0)
		return sdn;

	return tinhSDN(n / 10, sdn * 10 + n % 10);
}

void inNhiPhan(int n) {
	if (n == 0)
		return;
	inNhiPhan(n / 2);
	cout << n % 2;
}

int timUCLN(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		timUCLN(a - b, b);
	else
		timUCLN(a, b - a);
}

int tinhTgPascal(int i, int j) {
	if (j == 1 || i == j)
		return 1;

	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i - 1, j);
}

int main() {
	int h;

	cout << "n! = " << tinhGT(5) << endl;
	cout << "Tinh tong: " << tinhTong(3) << endl;
	cout << "Tinh tong BP: " << tinhTongBP(3) << endl;
	cout << "Tinh tong thuong: " << tinhTongThuong(4) << endl;
	cout << "Tinh tong GT: " << tinhTongGT(3) << endl;
	cout << "Tinh fibo: " << tinhFibo(5) << endl;
	cout << "Tinh luy thua: " << tinhLuyThua(0, -2) << endl;
	cout << "Dem chu so: " << demChuSo(12345) << endl;
	cout << "Tinh SDN: " << tinhSDN(12345) << endl;
	inNhiPhan(5);
	cout << endl;

	cout << "UCLN: " << timUCLN(24, 100) << endl;

	cout << "Nhap chieu cao: ";
	cin >> h;//h=5

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << tinhTgPascal(i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}