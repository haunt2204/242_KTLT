#include <iostream>
#include <string>
using namespace std;

#define SOMH 3
#define MAX 30

string loaiSv[] = { "Gioi", "Kha", "TB", "Duoi TB" };

struct NTN
{
	int d, m, y;
};

struct SinhVien
{
	int id;
	string hoTen;
	NTN ngaySinh;
	char queQuan[100];
	double diem[SOMH];
};

void nhapNTN(NTN &date) {
	cin >> date.d;
	cin.ignore();
	cin >> date.m;
	cin.ignore();
	cin >> date.y;
}

void xuatNTN(NTN date) {
	cout << date.d << "/" << date.m << "/" << date.y << endl;
}

//Theo diem trung binh
double tinhDTB(SinhVien sv) {
	double d1 = 0.0;
	for (int i = 0; i < SOMH; i++) {
		d1 += sv.diem[i];
	}
	return d1 / SOMH;
}

//Xep loai sinh vien
int xepLoaiSv(SinhVien sv) {
	double dtb = tinhDTB(sv);
	if (dtb >= 8)
		return 0;
	if (dtb >= 6.5)
		return 1;
	if (dtb >= 5)
		return 2;
	return 3;
}

void nhapSv(SinhVien &sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.id;
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);
	cout << "Nhap ngay sinh (cu phap: dd/mm/yyyy): ";
	nhapNTN(sv.ngaySinh);
	cout << "Nhap que quan: ";
	cin.ignore();
	cin.getline(sv.queQuan, 100);
	cout << "Nhap diem 3 mon hoc: ";
	for (int i = 0; i < SOMH; i++) {
		//cout << "MH thu " << i + 1 << ": ";
		cin >> sv.diem[i];
	}
}

void xuatSv(SinhVien sv) {
	cout << "=======================================\n";
	cout << "ID: " << sv.id << endl;
	cout << "Ho ten: " << sv.hoTen << endl;
	cout << "Ngay sinh: ";

	xuatNTN(sv.ngaySinh);

	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Diem: ";
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << endl;
	cout << "DTB: " << tinhDTB(sv) << endl;
	cout << "Xep loai: " << loaiSv[xepLoaiSv(sv)] << endl;
	cout << "=======================================\n";
}

//Xuat danh sach hoc bong: Danh sach SV dat hoc bong KKHT (dtb>=8)



void nhapDsSv(SinhVien *&ds, int &n) {
	//Nhap so luong sinh vien
	do {
		cout << "Nhap so phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Ngoai pham vi! Nhap lai!\n";
	} while (n <= 0 || n > MAX);
	//Xin cap phat vung nho
	ds = new SinhVien[n];
	//Nhap tung sinh vien
	for (int i = 0; i < n; i++) {
		nhapSv(ds[i]);
	}
}

void xuatDsSv(SinhVien *ds, int n) {
	if (ds != NULL) {
		for (int i = 0; i < n; i++) {
			xuatSv(ds[i]);
		}
	}
	else
		cout << "Danh sach rong!\n";
}

//Sap xep 
int cmpWithIdAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.id - sv2.id;
}

int cmpWithNameAsc(SinhVien sv1, SinhVien sv2) {
	return sv1.hoTen.compare(sv2.hoTen);
}

int cmpWithAvr(SinhVien sv1, SinhVien sv2) {
	double d1 = tinhDTB(sv1);//5.5
	double d2 = tinhDTB(sv2);//5.7
	
	return d1 < d2 ? -1 : (d1 > d2 ? 1 : 0);
}

//Sap xep theo que quan
int cmpWithAddress(SinhVien sv1, SinhVien sv2) {
	return strcmp(sv1.queQuan, sv2.queQuan);
}

void sortList(SinhVien *ds, int n, int func(SinhVien, SinhVien)) {
	if (ds != NULL) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (func(ds[j], ds[i]) < 0)
					swap(ds[j], ds[i]);
			}
		}
	}
}

int main() {
	//Thao tac tren danh sach sinh vien
	SinhVien *dssv = NULL;
	int n;

	nhapDsSv(dssv, n);
	xuatDsSv(dssv, n);

	cout << "=============SAP XEP================\n";
	sortList(dssv, n, cmpWithAddress);
	xuatDsSv(dssv, n);

	//Giai phong vung nho
	delete[]dssv;
	return 0;
}