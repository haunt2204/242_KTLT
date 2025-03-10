#include "Array1D.h"

int main() {
	//Khai bao mang
	int *a = NULL, n;

	srand(time(NULL));
	//Nhap so phan tu, xin cap phat vung nho
	/*inputArr(a, n);
	outputArr(a, n);*/
	//Thao tac tren mang

	//Sinh mang ngau nhien
	inputArr(a, n);
	outputArr(a, n);
	
	cout << "==============TIM KIEM======================\n";
	int key = 1;
	int size;
	int *res = find(a, n, key, size);

	outputArr(res, size);

	/*sortArr(a, n);
	outputArr(a, n);
	cout << isOrder(a, n) << endl;*/

	//Them phan tu moi vao mang
	/*int x = 999;
	pushBackArr(a, n, x);
	outputArr(a, n);*/

	//int* res = findExtremum(a, n);
	//cout << "Gia tri nho nhat: " << *res << endl;

	////Thao tac sap xep
	//cout << "=================SAP XEP================\n";
	//sortArr(a, n);
	//outputArr(a, n);

	////Thao tac dao nguoc mang
	//cout << "=================DAO NGUOC================\n";
	//reverseArr(a, n);
	//outputArr(a, n);

	//Noi 2 mang
	/*int *b = NULL, m;
	inputArr(b, m);
	outputArr(b, m);

	int size;
	int* c = concateArr(a, n, b, m, size);
	cout << "=============KET QUA NOI 2 MANG=============\n";
	outputArr(c, size);*/

	//Giai phong vung nho
	delete[]res;
	delete[]a;
	/*delete[]b;
	delete[]c;*/
	return 0;
}