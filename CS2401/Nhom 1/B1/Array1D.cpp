#include <iostream>
using namespace std;

#define MAX 100

void inputArr(int a[], int &n) {
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap n ngoai pham vi! Vui long nhap lai!\n";
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

//Tinh tong toan bo mang
bool def(int n) {
	return true;
}

//Tinh tong co dieu kien
int sumArr(const int a[], const int n, bool func(int)=def) {
	int tong = 0;

	for (int i = 0; i < n; i++) {
		if (func(a[i]))
			tong += a[i];
	}

	return tong;
}

bool asc(int a, int b) {
	return a < b;
}

bool desc(int a, int b) {
	return a > b;
}

//Sap xep mang tang dan (nguoi dung co the linh hoat thay doi thanh sap xep giam dan)
void sort(int a[], const int n, bool func(int,int)=asc) {
	for (int i = 0; i < n - 1; i++) {
		//Tim vi tri cua phan tu nho nhat trong day dang xet
		int minPos = i;
		for (int j = i + 1; j < n; j++)
			if (func(a[j], a[minPos]))
				minPos = j;
		//Hoan vi phan tu nho nhat voi phan tu dau day dang xet
		swap(a[i], a[minPos]);
	}
}

int main() {
	//Khai bao
	int a[MAX], n;

	//Nhap mang
	inputArr(a, n);

	//Xuat mang
	outputArr(a, n);

	//Thao tac tinh toan
	////Tinh tong cac phan tu trong mang

	cout << "Tong = " << sumArr(a, n, isDuong) << endl;

	//Sap xep
	sort(a, n);
	outputArr(a, n);

	return 0;
}