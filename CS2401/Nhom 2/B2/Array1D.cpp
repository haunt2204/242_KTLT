#include "vector.h"


int main() {
	//Khai bao 
	int* a, n;
	//int* b, m;
	//Khoi tao
	init(a, n);

	/*pushBackArr(a, n, 9);
	pushBackArr(a, n, 12);
	pushBackArr(a, n, 5);
	pushBackArr(a, n, 1);
	pushBackArr(a, n, 4);*/

	genArrRand(a, n);
	sort(a, n, isMax);

	outputArr(a, n);

	cout << isOrder(a, n) << endl;
	//init(b, m);
	////Xin cap phat
	//cout << "Nhap A:\n";
	//inputArr(a, n);
	//outputArr(a, n);
	//
	//cout << "Nhap B:\n";
	//inputArr(b, m);
	//outputArr(b, m);
	////Thao tac
	//int size;
	//int *res = concateArr(a, n, b, m, size);
	//outputArr(res, size);

	////Tim phan tu lon nhat
	//cout << "Phan tu lon nhat: " << *findExtremum(a, n, isMin) << endl;

	////Thao tac sap xep
	//cout << "===============SAP XEP=============\n";
	//sort(a, n, isMax);
	//outputArr(a, n);

	//cout << "===============DAO NGUOC=============\n";
	//reverseArr(a, n);
	//outputArr(a, n);
	//Giai phong
	//delete[]res;
	//delete[]b;
	delete[]a;
	return 0;
}