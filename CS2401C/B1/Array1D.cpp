#include <iostream>
using namespace std;

#define MAX 50

void inputArr(int a[], int& n) {
	//Nhap so luong phan tu
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;//n=-1
		system("cls");
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi cho phep! Vui long nhap lai!\n";
		
	} while (n <= 0 || n > MAX);
	//Nhap tung phan tu
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void outputArr(const int a[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

//Tinh toan trong mang 1 chieu
////Tinh tong toan bo mang
bool def(int n) {
	return true;
}

int sumArr(const int a[], const int n, bool func(int n)=def) {
	int tong = 0;

	for (int i = 0; i < n; i++) {
		if (func(a[i]))
			tong += a[i];
	}

	return tong;
}
////Tinh tong co dieu kien
//So chan
bool isChan(int n ) {
	return n % 2 == 0;
}
//So le
bool isLe(int n) {
	return n % 2 != 0;
}
//Chinh phuong
bool isChinhPhuong(int n) {
	//n = 4: i=1->n; i*i == n 
	/*int i = 1;
	while (i < n) {
		if (i*i == n)
			return true;
		i++;
	}
	return false;*/

	//int x = sqrt(n), x*x==n?
	int x = sqrt(n);
	return x*x == n;
}

//So nguyen to
bool isPrime(int n) {
	if (n < 2)
		return false;
	if (n > 2) {
		//n=7
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0)
				return false;
		}
	}
	return true;
}
//So duong
bool isDuong(int n) {
	return n >= 0;
}


//Ham sap xep mang 1 chieu: mac dinh sap xep tang dan 
//Nguoi dung co the linh hoat chuyen sang giam dan
bool asc(int a, int b) {
	return a < b;
}

void sortArr(int a[], const int n, bool func(int a, int b)=asc) {
	for (int i = 0; i < n - 1; i++) {
		//Tim vi tri phan tu nho nhat 
		int pos = i;
		for (int j = i + 1; j < n; j++) {
			if (func(a[j], a[pos]))
				pos = j;
		}
		//Hoan vi phan tu nho nhat voi phan tu dau day
		swap(a[i], a[pos]);
	}
}

bool desc(int a, int b) {
	return a > b;
}

//Them/xoa tai vi tri vt

int main() {
	//Khai bao mang
	int a[MAX], n;

	//Nhap xuat mang 1 chieu
	inputArr(a, n);
	outputArr(a, n);
	

	//Thao tac tinh toan
	int tong = sumArr(a, n);
	cout << tong << endl;

	//Thao tac sap xep
	sortArr(a, n, desc);
	outputArr(a, n);

	sortArr(a, n);
	outputArr(a, n);


	system("pause");
	return 0;
}