//Tiem vi tinh tai Nha Be, co 5 may tinh
//Moi luot, se co 5 khach hang den thue: Hiep, Vy, Uyen, An, Tuong
//Kha nang cua tung may tinh: 1, 2, 3, 2, 3
//Nhu cau cua tung khach hang: 2, 2, 1, 3, 3
#include <iostream>
using namespace std;

int* a, * p;
int n;

string tenKh[] = { "Hiep", "Vy", "Uyen", "An", "Tuong"};
int khaNang[] = { 1, 2, 3, 2, 3 };
int nhuCau[] = { 2, 2, 1, 3, 3 };

void print() {
	for (int i = 0; i < n; i++) {
		cout << "MT" << i+1 << "-" << tenKh[a[i]] << " ";
	}
	cout << endl;
}

void hoanVi(int i) {
	for (int j = 0; j < n; j++) {
		if (p[j] == 0 && khaNang[i]>=nhuCau[j]) {
			a[i] = j;
			p[j] = 1;

			if (i == n - 1)
				print();
			else
				hoanVi(i + 1);

			p[j] = 0;
		}
	}
}

int main() {
	//S = {1,2,3} => 6
	n = 5;

	a = new int[n];
	p = new int[n];

	for (int i = 0; i < n; i++) {
		p[i] = 0;
	}

	hoanVi(0);

	delete[]p;
	delete[]a;
	return 0;
}