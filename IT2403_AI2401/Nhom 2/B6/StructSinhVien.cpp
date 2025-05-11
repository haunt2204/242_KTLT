#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define SOMH 3

string xepLoai[] = { "DUOI_TB", "TB", "KHA", "GIOI" };
enum Loai { DUOI_TB, TB, KHA, GIOI };

struct SinhVien
{
	long long mssv;
	string hoTen;
	char queQuan[50];
	char ngaySinh[11];
	double diem[SOMH];
};

//Tinh diem trung binh
double tinhDTB(SinhVien sv) {
	double sum = 0;

	for (int i = 0; i < SOMH; i++) {
		sum += sv.diem[i];
	}

	return sum / SOMH;
}

//Xep loai SV
int xepLoaiSv(SinhVien sv) {
	double dtb = tinhDTB(sv);
	if (dtb >= 8)
		return GIOI;
	if (dtb >= 6.5)
		return KHA;
	if (dtb >= 5)
		return TB;
	return DUOI_TB;
}

//Kiem tra co dat hoc bong
bool isHocBong(SinhVien sv) {
	return tinhDTB(sv) >= 8;
}

//Nhap 1 Sv
void nhap1Sv(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cin.ignore();

	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);

	cout << "Nhap que quan: ";
	cin.getline(sv.queQuan, 50);

	cout << "Nhap ngay sinh (cu phap: dd/mm/yyyy): ";
	cin >> sv.ngaySinh;

	cout << "Nhap diem 3 mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		cin >> sv.diem[i];
	}
}

//Xuat 1 Sv
void xuat1Sv(SinhVien sv) {
	cout << "=======================================\n";
	cout << "ID: " << sv.mssv << endl;
	cout << "Ho ten: " << sv.hoTen << endl;
	cout << "Ngay sinh: " << sv.ngaySinh << endl;
	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Diem: ";
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << "\nDiem TB tich luy: " << tinhDTB(sv) << endl;
	cout << "Xep loai: " << xepLoai[xepLoaiSv(sv)] << endl;
	cout << "=======================================\n";
}

//Pham vi cua DSSV
struct DSSV
{
	SinhVien* ds;
	int soLuong;
};

void init(DSSV& l) {
	l.ds = NULL;
	l.soLuong = 0;
}

void xuatDsSv(DSSV l) {
	if (l.ds == NULL) {
		cout << "Danh sach rong!\n";
		return;
	}

	for (int i = 0; i < l.soLuong; i++) {
		xuat1Sv(l.ds[i]);
	}
}

//Them phan 01 phan tu moi vao mang hien co
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

//Doc du lieu tu tap tin
void readData(DSSV& l) {
	//Tao doi tuong nhap/xuat
	//Chi dinh duong dan (tuong doi): them tap tin --> working directory
	//Kiem tra trang thai (is_open())
	//Thao tac doc/xuat du lieu (eof())
	//Dong tap tin lai
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

//Sap xep theo diem TB
int cmpWithAvrAsc(SinhVien sv1, SinhVien sv2) {
	double d1 = tinhDTB(sv1);//5.5
	double d2 = tinhDTB(sv2);//5.3
	return d1 > d2 ? 1 : (d1 < d2 ? -1 : 0);
}

//Sap xep danh sach: tang dan
void sort(DSSV l, int func(SinhVien, SinhVien)=cmpWithIdAsc) {
	for (int i = 0; i < l.soLuong - 1; i++) {
		for (int j = i + 1; j < l.soLuong; j++) {
			if (func(l.ds[j], l.ds[i])<0) {
				swap(l.ds[i], l.ds[j]);
			}
		}
	}
}

void xuatDsHocBong(DSSV l) {
	ofstream outFile("data_sv_hb.txt");
	if (outFile.is_open()) {
		//Ghi du lieu ra tap tin
		for (int i = 0; i < l.soLuong; i++) {
			if (isHocBong(l.ds[i])) {
				outFile << l.ds[i].mssv << "$"
					<< l.ds[i].hoTen << "$"
					<< l.ds[i].queQuan << "$"
					<< l.ds[i].ngaySinh << "$";
				for (int j = 0; j < SOMH; j++) {
					outFile << l.ds[i].diem[j] << " ";
				}
				outFile << endl;
			}
		}

		cout << "Da xuat thanh cong!\n";

		outFile.close();
	}
}

//Tim kiem
SinhVien* timKiem(DSSV l, long long id) {
	SinhVien *res = NULL;

	for (int i = 0; i < l.soLuong; i++) {
		if (l.ds[i].mssv == id) {
			res = &l.ds[i];
			break;
		}
	}
	return res;
}

//Ham cung ten
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

	cout << "===============SAP XEP==============\n";
	sort(l1, cmpWithAvrAsc);
	xuatDsSv(l1);
	/*xuatDsHocBong(l1);*/
	cout << "===============KQ TIM KIEM==============\n";
	vector<SinhVien> res = timKiem(l1, "Do Thao Duyen");

	if (res.size() > 0) {
		//cout << res->hoTen << "-" << res->queQuan;
		/*xuatDsSv(res);*/
		for (int i = 0; i < res.size(); i++) {
			xuat1Sv(res[i]);
		}
	}
	else
		cout << "KHONG TIM THAY!\n";


	delete[]l1.ds;
	return 0;
}