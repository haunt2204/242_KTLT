#include <iostream>
using namespace std;

#define SIZE 8

int queens[SIZE] = {0};

void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (j == queens[i])
				cout << "Q\t";
			else
				cout << "-\t";
		}
		cout << endl;
	}
	cout << "===================\n";
}

bool canPutQueen(int i, int j) {
	//Kiem tra
	for (int k = 0; k < i; k++) {
		if (queens[k] == j || abs(i-k)==abs(j-queens[k]))
			return false;
	}
	return true;
}

void putQueen(int i) {
	for (int j = 0; j < SIZE; j++) {
		//Kiem tra coi co dat quan hau duoc hay khong
		if (canPutQueen(i, j)) {
			queens[i] = j;
			if (i == SIZE - 1) {
				print();
			}
			else
				putQueen(i + 1);
			//Lan nguoc di tim ket qua moi
			queens[i] = 0;
		}
	}
}

int main() {
	putQueen(0);
	return 0;
}