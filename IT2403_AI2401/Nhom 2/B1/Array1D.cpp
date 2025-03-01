#include <iostream>
using namespace std;

#define MAX 50

void inputArr(int a[], int &n) {
	//Nhap so phan tu
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap ngoai pham vi! Nhap lai!\n";
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

//Tinh toan tren mang 1 chieu: tinh tong mang, tinh tong cac phan tu la so chan, so le, so chinh phuong, so nguyen to,...
bool isChan(int n) {
	return n % 2 == 0;
}

bool isLe(int n) {
	return n % 2 != 0;
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

//Thao tac sap xep tren mang 1D: mac dinh sap tang dan, chuyen sang giam dan
bool asc(int a, int b) {
	return a < b;
}

void sort(int a[], int n, bool func(int, int)=asc) {
	//selection sort
	for (int i = 0; i < n - 1; i++) {
		//Tim vi tri nho nhat trong day
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
//Tai su dung, khong lap code va de mo rong trong tuong lai

int main() {
	//Khai bao
	int a[MAX], n;

	//Thao tac nhap/xuat
	inputArr(a, n);
	outputArr(a, n);
	

	//Thao tac tinh toan tren mang
	int tong = sumArr(a, n);
	cout << tong << endl;

	//Sap xep mang
	sort(a, n, desc);
	outputArr(a, n);

	return 0;
}