#include "vector.h"

int main() {
	//Khai bao
	int* a, * b;
	int n, m;

	srand(time(NULL));

	//Khoi tao rong
	init(a, n);
	//init(b, m);

	//Xin cap phat
	//genArrRand(a, n);
	//cout << "Nhap A:\n";
	//inputArr(a, n);

	pushBackArr(a, n, 1);
	pushBackArr(a, n, 3);
	pushBackArr(a, n, 5);
	pushBackArr(a, n, 1);
	pushBackArr(a, n, 1);
	outputArr(a, n);
	int key, size;

	cout << "Nhap gia tri can tim: ";
	cin >> key;

	int *res = find(a, n, key, size);

	cout << "============TIM KIEM===============\n";
	outputArr(res, size);

	///*cout << "Nhap B:\n";
	//inputArr(b, m);
	//outputArr(b, m);*/
	////Thao tac tinh toan

	//cout << *findExtremum(a, n, isMin) << endl;

	////Thao tac sap xep
	//cout << "=============SAP XEP==================\n";
	//sortArr(a, n);
	//outputArr(a, n);

	//cout << "=============DAO NGUOC MANG==================\n";
	//reverseArr(a, n);
	//outputArr(a, n);

	/*cout << "=============THEM PHAN TU==================\n";
	pushBackArr(a, n, 9999);
	outputArr(a, n);*/

	/*cout << "=============NOI MANG==================\n";
	int* res, size;

	res = concateArr(a, n, b, m, size);
	outputArr(res, size);*/

	//Giai phong vung nho
	/*delete[]res;
	delete[]b;*/
	delete[]a;
	return 0;
}