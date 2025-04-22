#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define SOMH 3

string loai[] = { "Duoi TB", "TB", "Kha", "Gioi" };
enum loai { DUOI_TB, TB, KHA, GIOI };

struct SinhVien
{
	long long mssv;
	string hoTen;
	char queQuan[50];
	char ngaySinh[11];
	double diem[SOMH];
};

struct DSSV
{
	SinhVien* ds;
	int soLuong;
};

void init(DSSV& l) {
	l.ds = NULL;
	l.soLuong = 0;
}

double tinhDiemTB(SinhVien sv) {
	double sum = 0;
	for (int i = 0; i < SOMH; i++) {
		sum+=sv.diem[i];
	}
	return sum / SOMH;
}

int xepLoai(SinhVien sv) {
	double dtb = tinhDiemTB(sv);
	if (dtb >= 8.0)
		return GIOI;//GIOI
	if (dtb >= 6.5)
		return KHA;//KHA
	if (dtb >= 5.0)
		return TB;//TB
	return DUOI_TB;//DUOI_TB
}

bool isHocBong(SinhVien sv) {
	return tinhDiemTB(sv)>=8;
}

void nhap1Sv(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cin.ignore();

	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);

	cout << "Nhap ngay sinh (cu phap: dd/mm/yyyy): ";
	cin >> sv.ngaySinh;
	cin.ignore();

	cout << "Nhap que quan: ";
	cin.getline(sv.queQuan, 100);

	cout << "Nhap diem 3 mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		cin >> sv.diem[i];
	}
}

void xuat1Sv(SinhVien& sv) {
	cout << "=======================================\n";
	cout << "ID: " << sv.mssv << endl;
	cout << "Ho ten: " << sv.hoTen << endl;
	cout << "Ngay sinh: " << sv.ngaySinh << endl;
	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Diem: ";
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << "\nDiem TB tich luy: " << tinhDiemTB(sv) << endl;
	cout << "Xep loai: " << loai[xepLoai(sv)] << endl;
	cout << "=======================================\n";
}

void printList(DSSV l) {
	if (l.ds == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}
	for (int i = 0; i < l.soLuong; i++) {
		xuat1Sv(l.ds[i]);
	}
}

void pushBackArr(SinhVien*& a, int& n, SinhVien newElm) {
	if (a == NULL) {
		n = 1;
		a = new SinhVien[n];
		a[0] = newElm;
	}
	else {
		SinhVien* newArr = new SinhVien[n + 1];
		for (int i = 0; i < n; i++) {
			newArr[i] = a[i];
		}

		newArr[n] = newElm;

		delete[]a;
		a = newArr;
		n++;
	}
}


void readData(DSSV& l) {
	//Tao doi tuong nhap/xuat
	//Chi dinh duong dan (tuong doi): them tap tin vao --> working directory
	//Kiem tra trang thai (is_open())
	//Doc hoac xuat (eof())
	//Dong tap tin lai (close())
	ifstream inFile;
	
	inFile.open("SinhVien.txt");
	
	if (inFile.is_open()) {
		
		while (!inFile.eof()) {
			SinhVien sv;

			inFile >> sv.mssv;
			inFile.ignore();
			getline(inFile, sv.hoTen, '#');
			inFile.getline(sv.queQuan, 50, '#');
			inFile.getline(sv.ngaySinh, 11, '#');
			for (int i = 0; i < SOMH; i++) {
				inFile >> sv.diem[i];
			}

			pushBackArr(l.ds, l.soLuong, sv);
		}

		inFile.close();
	}
}

int cmpWithIdAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.mssv - sv2.mssv;
}

int cmpWithNameAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.hoTen.compare(sv2.hoTen);
}

int cmpWithAddAsc(SinhVien sv1, SinhVien sv2) {
	return strcmp(sv1.queQuan, sv2.queQuan);
}

//Sap xep theo diem trung binh
int cmpWithAvrAsc(SinhVien sv1, SinhVien sv2) {
	double d1 = tinhDiemTB(sv1);//5.5
	double d2 = tinhDiemTB(sv2);//5.333
	//Xu ly tiep
	return d1 > d2 ? 1 : (d1 < d2 ? -1 : 0);
}

void sortList(DSSV& l, int func(SinhVien, SinhVien)) {
	if (l.ds!=NULL) {
		for (int i = 0; i < l.soLuong - 1; i++) {
			for (int j = i + 1; j < l.soLuong; j++) {
				if (func(l.ds[j], l.ds[i])<0) {
					swap(l.ds[i], l.ds[j]);
				}
			}
		}
	}
}

void xuatHocBong(DSSV l) {
	ofstream outFile("data_sv_hb.txt");
	if (outFile.is_open()) {
		for (int i = 0; i < l.soLuong; i++) {
			if (isHocBong(l.ds[i])) {
				outFile << l.ds[i].mssv << '$'
					<< l.ds[i].hoTen << '$'
					<< l.ds[i].queQuan << '$'
					<< l.ds[i].ngaySinh << '$';
				for (int j = 0; j < SOMH; j++) {
					outFile << l.ds[i].diem[j] << " ";
				}
				outFile << endl;
			}
		}
		outFile.close();
	}
}

SinhVien* timKiem(DSSV l, long long id) {
	SinhVien* res = NULL;

	for (int i = 0; i < l.soLuong; i++) {
		if (l.ds[i].mssv == id) {
			res = &l.ds[i];
			break;
		}
	}

	return res;
}

//Ham cung ten
//Cach 1:
//DSSV timKiem(DSSV l, string name) {
//	DSSV res;
//	init(res);
//
//	for (int i = 0; i < l.soLuong; i++) {
//		if (l.ds[i].hoTen == name) {
//			pushBackArr(res.ds, res.soLuong, l.ds[i]);
//		}
//	}
//
//	return res;
//}

//Cach 2:
vector<SinhVien> timKiem(DSSV l, string name) {
	vector<SinhVien> res;

	for (int i = 0; i < l.soLuong; i++) {
		if (l.ds[i].hoTen == name) {
			res.push_back(l.ds[i]);
		}
	}

	return res;
}

int main() {
	DSSV l1;
	init(l1);

	readData(l1);
	//Xuat danh sach 

	cout << "==============KQ SAP XEP============\n";
	sortList(l1, cmpWithAvrAsc);
	printList(l1);

	//xuatHocBong(l1);

	cout << "==============KQ TIM KIEM============\n";
	vector<SinhVien> res = timKiem(l1, "Do Thao Duyen");
	
	if (res.size() > 0) {
		//cout << res->hoTen;
		/*xuat1Sv(*res);*/
		for (int i = 0; i < res.size(); i++) {
			xuat1Sv(res[i]);
		}
	}
	else
		cout << "Khong tim thay!\n";

	delete[]l1.ds;
	return 0;
}