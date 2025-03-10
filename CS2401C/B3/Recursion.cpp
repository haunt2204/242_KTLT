#include <iostream>
using namespace std;

//int tinhGT(int n) {
//	//Basic case
//	if (n == 1)
//		return 1;
//	//General case
//	return n*tinhGT(n - 1);
//}

int tinhGT(int n, int gt=1) {
	//Basic case
	if (n == 1)
		return gt;
	//General case
	return tinhGT(n - 1,gt*n);
}

int tinhTong(int n, int tong = 0) {
	//Basic case
	if (n == 0)
		return tong;
	//General case
	return tinhTong(n - 1, n + tong);
}

int tinhTongBP(int n, int tong = 0) {
	//Basic case
	if (n == 0)
		return tong;
	//General case
	return tinhTongBP(n - 1, n*n + tong);
}

double tinhTongThuong(int n, double tong = 0) {
	if (n <= 0)
		return tong;
	if (n % 2 == 0)
		return tinhTongThuong(n - 1, tong);
	return tinhTongThuong(n - 2, 1.0 / n + tong);
}

int tinhFibo(int n, int a = 0, int b = 1) {
	//Basic case
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	//General case
	return tinhFibo(n - 1, b, a + b);
}

double tinhLuyThua(int x, int n, double res=1.0) {
	if (n == 0)
		return res;

	if (n > 0) {
		return tinhLuyThua(x, n - 1, res*x);
	}
	else {
		if (x == 0)
			return -1;//Loi chia 0

		return tinhLuyThua(x, n + 1, (1.0 / x)*res);
	}
		
}

int demChuSo(int n, int dem = 0) {
	//Basic case
	if (n == 0)
		return dem;
	//General case
	return demChuSo(n / 10, dem + 1);
}

int tinhSDN(int n, int sdn = 0) {
	//Basic case
	if (n == 0)
		return sdn;
	//General case
	return tinhSDN(n/10, sdn*10+n%10);
}

void inNhiPhan(int n) {
	if (n <= 0)
		return;
	inNhiPhan(n / 2);
	cout << n % 2;
}

int timUCLN(int a, int b) {
	//Basic case
	if (a == b)
		return a;
	//General case
	if (a > b)
		return timUCLN(a - b, b);
	else
		return timUCLN(a, b - a);
}

int tinhTgPascal(int i, int j) {
	//Basic case
	if (j == 1 || i == j)
		return 1;
	//General case
	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i-1, j);
}

int main() {

	/*cout << "KQ tinh giai thua: " << tinhGT(5) << endl;
	cout << "KQ tinh tong: " << tinhTong(3) << endl;
	cout << "KQ tinh tong binh phuong: " << tinhTongBP(3) << endl;
	cout << "KQ tinh tong thuong: " << tinhTongThuong(5) << endl;
	cout << "KQ tinh Fibo: " << tinhFibo(5) << endl;
	cout << "KQ tinh luy thua: " << tinhLuyThua(2,-2) << endl;
	cout << "KQ dem so chu so cua n: " << demChuSo(123456) << endl;
	cout << "KQ tinh SDN cua n: " << tinhSDN(123456) << endl;
	cout << "KQ chuyen tu thap phan sang nhi phan: ";
	inNhiPhan(5);
	cout << endl;

	cout << "KQ tim UCLN: " << timUCLN(9, 6) << endl;*/

	int h;
	cout << "Nhap chieu cao: ";
	cin >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << tinhTgPascal(i, j) <<" ";
		}
		cout << endl;
	}

	return 0;
}