#include <iostream>
using namespace std;

#define MAX 30

void inputArr(int a[], int& n) {
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void outputArr(const int a[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

//Tinh tong co dieu kien: so chan, so le, so am, so duong, so nguyen to, so chinh phuong,...
bool def(int n) {
	return true;
}

int sumArr(const int a[], const int n, bool func(int)=def) {
	int tong = 0;

	for (int i = 0; i < n; i++) {
		if(func(a[i]))
			tong += a[i];
	}

	return tong;
}

//Kiem tra so am
bool isAm(int n) {
	return n < 0;
}

//Kiem tra so duong
bool isDuong(int n) {
	//if (n >= 0) return true;
	//return false;
	return n >= 0;
}

//Kiem tra so nguyen to
bool isNguyenTo(int n) {
	if (n < 2)
		return false;

	if (n > 2) {
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				return false;
	}

	return true;
}

//Kiem tra so chinh phuong
bool isChinhPhuong(int n) {
	//Cach 1
	/*int i = 1;
	while (i*i <= n) {
		if (i*i == n) return true;
		i++;
	}
	return false;*/
	//Cach 2
	int tam = sqrt(n);
	return tam * tam == n;

}

//Thao tac sap xep mang 1 chieu: mac dinh sap tang dan 
//Nguoi dung co the linh hoat thay doi thanh giam dan

int asc(int a, int b) {
	/*if (a < b)
		return 1;
	else if (a > b)
		return -1;
	return 0;*/
	return b - a;
}

int desc(int a, int b) {
	return a - b;
}

void sort(int a[], const int n, int func(int, int)=asc) {
	for (int i = 0; i < n - 1; i++) {
		//Tim vi tri phan tu nho nhat/lon nhat trong day
		int pos = i;
		for (int j = i + 1; j < n; j++) {
			if (func(a[j], a[pos])>0)
				pos = j;
		}
		//Hoan vi phan tu min/max voi phan tu dau day
		swap(a[i], a[pos]);
	}
}


int main() {
	//Khai bao mang 1D
	int a[MAX], n;

	//Ham nhap mang 
	inputArr(a, n);
	//Xuat mang
	outputArr(a, n);
	//Tinh toan don gian
	/*int tong = tinhTongMang(a, n);*/
	cout << sumArr(a, n) << endl;

	//Sap xep mang 1 chieu
	sort(a, n);
	outputArr(a, n);

	return 0;
}