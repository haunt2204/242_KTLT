#include "vector.h"



int main() {
	//Khai bao
	int* a, n;
	int* b, m;
	//Khoi tao
	init(a, n);
	/*init(b, m);*/
	//Xin cap phat
	//cout << "Nhap A: ";
	//inputArr(a, n);

	pushBackArr(a, n, 1);//0
	pushBackArr(a, n, 1);//1
	pushBackArr(a, n, 4);
	pushBackArr(a, n, 1);//3
	pushBackArr(a, n, 7);

	int key;

	cout << "Nhap gia tri can tim: ";
	cin >> key;

	int size;

	int* res = find(a, n, key, size);

	if (res != NULL)
		outputArr(res, size);
	else
		cout << "Khong tim thay!\n";
	/*srand(time(NULL));
	genArrRand(a, n);*/

	outputArr(a, n);

	//sort(a, n,isMax);

	/*outputArr(a, n);
	cout << isOrder(a, n,isMax) << endl;*/

	/*cout << "Nhap B: ";
	inputArr(b, m);
	outputArr(b, m);

	cout << "==============NOI MANG==================\n";
	int size;
	int* res = concateArr(a, n, b, m, size);
	outputArr(res, size);*/

	//Thao tac tren mang 1D
	/*cout << *findExtremum(a, n,isMin) << endl;*/

	////Thao tac sap xep
	//cout << "==============SAP XEP==================\n";
	//sort(a, n, isMax);
	//outputArr(a, n);

	//cout << "==============DAO NGUOC==================\n";
	//reverseArr(a, n);
	//outputArr(a, n);
	
	//Giai phong vung nho
	/*delete[]res;
	delete[]b;*/
	delete[]a;
	return 0;
}