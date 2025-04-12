//Tiem vi tinh tai Nha Be, co 5 may tinh
//Moi luot, se co 5 khach hang den thue: Trang, Nhu, Kiet, Loc, Oanh
//Kha nang cua tung may tinh: 1, 2, 3, 2, 3
//Nhu cau cua tung khach hang: 2, 2, 1, 3, 3
#include <iostream>
using namespace std;

int* a, * p;
int n;

string tenKh[] = {"Trang", "Nhu","Kiet", "Loc", "Oanh"};
int khaNang[] = { 1, 2, 3, 2, 3 };
int nhuCau[] = { 2, 2, 1, 3, 3 };

void print() {
	for (int i = 0; i < n; i++) {
		cout << "MT" << i+1 << "-" << tenKh[a[i]] << " ";
	}
	cout << endl;
}

void hoanVi(int i) {
	//Tai buoc co nhieu cach chon, ta chon thu 1 cach
	for (int j = 0; j < n; j++) {
		if (p[j] == -1 && khaNang[i]>=nhuCau[j]) {
			a[i] = j;
			p[j] = 1;

			if (i == n - 1)
				print();
			else
				hoanVi(i + 1);
			//Phuc hoi trang thai
			p[j] = -1;
		}
	}
	//Neu thanh cong thi ghi nhan, lan nguoc de tim kq khac

	//Neu khong thanh cong, thi lan nguoc di tim cach khac
}

int main() {
	//S = {1,2,3} => 6
	n = 5;

	a = new int[n];
	p = new int[n];

	for (int i = 0; i < n; i++) {
		p[i] = -1;
	}

	hoanVi(0);

	delete[]p;
	delete[]a;
	return 0;
}