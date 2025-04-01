#include <iostream>
using namespace std;

#define SIZE 5

int banCo[SIZE][SIZE] = { {0} };
int dd[] = { -2,-2,-1,1,2,2,1,-1 };
int dc[] = { -1,1,2,2,1,-1,-2,-2 };

void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << banCo[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "===============================\n";
}

void nuocDi(int n, int vtD, int vtC) {
	//Tai buoc co nhieu cach di, di thu 1 cach
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
			banCo[dMoi][cMoi] = 0; //Phuc hoi trang thai
		}
	}
}


int main() {
	banCo[2][2] = 1;

	nuocDi(2, 2, 2);

	return 0;
}