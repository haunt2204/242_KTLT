#include <iostream>
using namespace std;

#define SIZE 5

int banCo[SIZE][SIZE] = { {0} };
int dd[] = { -2,-2,-1,1,2,2,1,-1 };
int dc[] = { -1,1,2,2,1,-1,-2,-2 };

//Ghi nhan ket qua
void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << banCo[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=========================\n";
}

void nuocDi(int n, int vtD, int vtC) {
	//Tai buoc co nhieu cach chon, ta chon thu 1 cach
	for (int i = 0; i < 8; i++) {
		int dMoi = vtD + dd[i];
		int cMoi = vtC + dc[i];

		if (dMoi >= 0 && dMoi < SIZE && cMoi >= 0 && cMoi < SIZE && banCo[dMoi][cMoi] == 0) {
			banCo[dMoi][cMoi] = n;

			if (n == SIZE * SIZE) {
				print();
			}
			else
				nuocDi(n + 1, dMoi, cMoi);
			//Phuc hoi trang thai
			banCo[dMoi][cMoi] = 0;
		}
	}
	//Neu thanh cong thi ghi nhan, lan nguoc de tim kq khac

	//Neu khong thanh cong, thi lan nguoc di tim cach khac
}

int main() {
	banCo[0][0] = 1;
	nuocDi(2, 0, 0);
	return 0;
}