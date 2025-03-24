//Tiệm vi tính tại VVT có 5 máy tính, mỗi thời điểm có 5 KH đến thuê.
//Hãy liệt kê các cách bố trí khách hàng vào các máy tính.
#include <iostream>
#include <string>
using namespace std;

int *a, *p;
int n;

string khachHang[] = {"An", "Khanh", "Nam", "Nhung", "Kha"};

int nhuCau[] = { 1,1,1,3,2 };
int khaNang[] = { 1,2,3,1,2 };

void print() {
	for (int i = 0; i < n; i++) {
		cout << "MT" << (i+1) << "-" << khachHang[a[i] - 1] << " ";
	}
	cout << endl;
}

void hoanVi(int i) {
	for (int j = 1; j < n + 1; j++) {
		if (p[j] == 0 && khaNang[i]>=nhuCau[j-1]) {
			a[i] = j;
			p[j] = 1;

			if (i == n - 1) {
				print();
			}
			else
				hoanVi(i + 1);

			p[j] = 0;
		}
	}
}

int main() {
	n = 5;

	a = new int[n];
	p = new int[n + 1];

	for (int i = 0; i < n + 1; i++) {
		p[i] = 0;
	}

	hoanVi(0);

	delete[]p;
	delete[]a;
	return 0;
}