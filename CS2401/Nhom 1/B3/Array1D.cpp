#include "vector.h"

int main() {
	//Khai bao
	int* a, n;
	/*int* b, m;
	int* res, size;*/

	//Khoi tao rong
	init(a, n);
	/*init(b, m);*/

	//genArrRand(a, n);

	pushBackArr(a, n, 3);
	pushBackArr(a, n, 5);
	pushBackArr(a, n, 9);
	pushBackArr(a, n, 5);
	pushBackArr(a, n, 10);

	outputArr(a, n);

	int size;

	int *res = find(a, n, 5, size);

	if (res != NULL) {
		outputArr(res, size);
		for (int i = 0; i < size; i++) {
			cout << a[res[i]] << " ";
		}
	}
	else
		cout << "Khong tim thay!\n";

	//Thao tac xin cap phat vung nho, nhap/xuat mang
	/*cout << "Nhap a:\n";
	inputArr(a, n);*/
	
	/*cout << "Nhap b:\n";
	inputArr(b, m);
	outputArr(b, m);

	cout << "===============NOI MANG===============\n";
	
	res = concateArr(a, n, b, m, size);
	outputArr(res, size);*/

	////Tim phan tu lon nhat
	//cout << *findExtremum(a, n, isMin) << endl;

	////Sap xep mang
	//cout << "=====================SAP XEP==============\n";
	//sort(a, n, isMax);
	//outputArr(a, n);

	//Giai phong vung nho
	delete []a;
	/*delete[]b;
	delete[]res;*/
	return 0;
}