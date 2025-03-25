#include <iostream>
using namespace std;

//int tinhTong(int n) {
//	//Basic case
//	if (n == 1)
//		return 1;
//	//General case
//	return n + tinhTong(n - 1);
//}

int tinhTong(int n, int sum=0) {
	//Basic case
	if (n == 0)
		return sum;
	//General case
	return tinhTong(n - 1, n + sum);
}

int tinhTongBP(int n, int sum = 0) {
	//Basic case
	if (n == 0)
		return sum;
	//General case
	return tinhTongBP(n - 1, n*n + sum);
}

//n! = n*(n-1)!
int tinhGT(int n, int gt = 1) {
	if (n == 0)
		return gt;
	return tinhGT(n - 1, n*gt);
}

int tinhTongGT(int n, int sum = 0) {
	//Basic case
	if (n == 0)
		return sum;
	//General case
	return tinhTongGT(n - 1, tinhGT(n) + sum);
}

//n = 6; 1/1+1/3+1/5
double tinhTongThuong(int n, double sum = 0) {
	if (n <= 0)
		return sum;

	if (n % 2 == 0)
		return tinhTongThuong(n - 1, sum);

	return tinhTongThuong(n - 2, 1.0 / n + sum);
}

int tinhFibo(int n) {
	/*if (n == 0)
		return 0;
	if (n == 1)
		return 1;*/
	if (n == 0 || n == 1)
		return n;

	return tinhFibo(n - 1) + tinhFibo(n - 2);
}

double tinhLuyThua(int x, int n, double res=1) {
	if (n == 0)
		return res;

	if (n < 0) {
		if (x == 0)
			return -1;//Loi chia cho so 0
		return tinhLuyThua(x, n + 1, (1.0 / x) * res);
	}

	return tinhLuyThua(x, n - 1, x*res);
}

int demChuSo(int n, int dem = 0) {
	if (n == 0)
		return dem;

	return demChuSo(n / 10, 1 + dem);
}

int tinhSDN(int n, int sdn = 0) {
	if (n == 0)
		return sdn;

	return tinhSDN(n / 10, sdn * 10 + n % 10);
}

void inNhiPhan(int n) {
	//Basic case
	if (n == 0)
		return;
	//General case
	inNhiPhan(n / 2);
	cout << n % 2;
}

int timUCLN(int a, int b) {
	if (a == b)
		return a;
	if (a > b)
		return timUCLN(a - b, b);
	else
		return timUCLN(a, b - a);
}

int tinhTgPascal(int i, int j) {
	if (j == 1 || i == j)
		return 1;

	return tinhTgPascal(i - 1, j - 1) + tinhTgPascal(i - 1, j);
}

int main() {

	cout << "Ket qua tinh tong: " << tinhTong(3) << endl;
	cout << "Ket qua tinh tong: " << tinhTongBP(3) << endl;
	cout << "Tinh giai thua: " << tinhGT(3) << endl;
	cout << "Tinh tong giai thua: " << tinhTongGT(3) << endl;
	cout << "Tinh tong thuong: " << tinhTongThuong(3) << endl;
	cout << "Tinh fibo: " << tinhFibo(5) << endl;
	cout << "Tinh luy thua: " << tinhLuyThua(0, -2) << endl;
	//Xu ly ngoai le cho bai tinh luy thua
	//int n, x;
	//cin >> x >> n;
	//if (x == 0) {
	//	if (n < 0)
	//		cout << "Loi chia so 0!";
	//	else if (n == 0)
	//		cout << "Phep tinh khong hop le!\n";
	//	else {

	//	}
	//}
	//else {
	//	//
	//}

	cout << "Dem chu so: " << demChuSo(12345) << endl;
	cout << "Tim SDN: " << tinhSDN(12345) << endl;
	cout << "In nhi phan: ";
	inNhiPhan(4);
	cout << endl;

	cout << "Tim UCLN: " << timUCLN(8,6) << endl;

	int h;
	cout << "Nhap chieu cao tam giac: ";
	cin >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cout << tinhTgPascal(i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}