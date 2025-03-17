#include <iostream>
using namespace std;

int *a, *p;
int n;

void print() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

void hoanVi(int i) {
	//Tai buoc co nhieu cach chon thi chon thu 1 cach
	for (int j = 1; j < n + 1; j++) {
		if (p[j] == 0) {
			a[i] = j;
			p[j] = 1;

			//Neu da tim duoc 1 truong hop nghiem: ghi nhan
			if (i == n - 1) {
				//Ghi nhan
				print();
			}
			else
				hoanVi(i + 1);
			//Lan nguoc de tim ket qua moi, phuc hoi trang thai (go the xuong)
			p[j] = 0;
		}
	}
}

int main() {
	n = 3;

	a = new int[n];
	p = new int[n+1];

	//Khao tao rong cho mang danh dau
	for (int i = 0; i < n + 1; i++) {
		p[i] = 0;
	}
	//Thao tac

	hoanVi(0);

	//Giai phong
	delete[]p;
	delete[]a;
	return 0;
}