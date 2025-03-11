#include <iostream>
using namespace std;

#define MAX 50

void inputArr(int a[], int& n) {
	//Nhap so luong phan tu
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
	//Nhap tung phan tu trong mang
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void outputArr(const int a[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}

//Tinh tong cac phan tu trong mang 1 chieu (co dieu kien)
//Tinh cac phan tu la: so duong, so am, chan, le, nguyen to, chinh phuong,...
bool def(int n) {
	return true;
}

int sumArr(int a[], int n, bool func(int)=def) {
	int tong = 0;
	
	for (int i = 0; i < n; i++) {
		if(func(a[i]))
			tong += a[i];
	}

	return tong;
}

bool isDuong(int n) {//100
	return n >= 0;
}

bool isChan(int n) {
	return n % 2 == 0;
}

//Kiem tra so nguyen to
bool isPrime(int n) {
	if (n < 2)
		return false;
	if (n > 2) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

//Kiem tra so chinh phuong
bool isChinhPhuong(int n) {
	int x = sqrt(n);
	return (x*x == n);
}

//Sap xep mang 1 chieu: mac dinh sap tang dan (nguoi dung linh hoat chuyen sang giam dan)
bool asc(int a, int b) {
	return a < b;
}

void sort(int a[], const int n, bool func(int, int)=asc) {
	for (int i = 0; i < n - 1; i++) {
		//Tim vi tri phan tu nho nhat trong day
		int pos = i;
		for (int j = i + 1; j < n; j++) {
			if (func(a[j], a[pos]))
				pos = j;
		}
		//Hoan vi voi phan tu dau day
		swap(a[i], a[pos]);
	}
}

bool desc(int a, int b) {
	return a > b;
}

int main() {
	//Khai bao mang tinh
	int a[MAX], n;

	//Nhap va xuat mang 1 chieu
	inputArr(a, n);
	outputArr(a, n);
	cout << endl;

	//Thao tac tinh toan
	int tong = sumArr(a, n);
	cout << tong << endl;

	//Sap xep mang 1 chieu
	sort(a, n);
	outputArr(a, n);

	return 0;
}