#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Yeu cau 1:
struct Sach {
    char maSach[5];
    string tenSach;
    char tenTacGia[50];
    double giaBan;
    int giamGia; //%
};

void nhap1Sach(Sach &s){
    cout << "=========NHAP THONG TIN=======\n";
    cout << "Nhap ma sach: ";
    cin >> s.maSach;
    cin.ignore();
    
    cout << "Nhap ten sach: ";
    getline(cin, s.tenSach);
    
    cout << "Nhap ten tac gia: ";
    cin.getline(s.tenTacGia, 50);
    
    cout << "Nhap gia ban: ";
    cin >> s.giaBan;
    
    cout << "Nhap giam gia: ";
    cin >> s.giamGia;
}

void xuat1Sach(const Sach s){
    cout << "=========XUAT THONG TIN=======\n";
    cout << "Ma sach: " << s.maSach << endl;
    cout << "Ten sach: " << s.tenSach << endl;
    cout << "Tac gia: " << s.tenTacGia << endl;
    cout << "Gia ban: " << s.giaBan << endl;
    cout << "Giam gia: " << s.giamGia << endl;
    cout << "==============================\n";
}

double tinhTien(Sach s){
    return s.giaBan * (100 - s.giamGia)/100;
}

//Yeu cau 2:

struct DSQS {
    Sach *ds;
    int soLuong;
};

void init(DSQS &l){
    l.ds = NULL;
    l.soLuong = 0;
}

void xuatDsSach(DSQS l){
    for(int i=0; i<l.soLuong; i++){
        xuat1Sach(l.ds[i]);
    }
}

//Dung de quy (duoi): ????
double tinhTongHD(DSQS cart){
    double res = 0;
    
    for(int i=0; i<cart.soLuong; i++){
        res += tinhTien(cart.ds[i]);
    }
    
    return res;
}

void pushBackArr(Sach*& a, int& n, Sach newElm) {
    if (a == NULL) {
        n = 1;
        a = new Sach[n];
        a[0] = newElm;
    }
    else {
        Sach* newArr = new Sach[n + 1];
        for (int i = 0; i < n; i++) {
            newArr[i] = a[i];
        }
        
        newArr[n] = newElm;
        
        delete[]a;
        a = newArr;
        n++;
    }
}

void readData(DSQS &l){
    //Tao doi tuong doc tap tin
    //Chi dinh duong dan: tuong doi
    //Kiem tra trang thai: is_open()
    //Doc du lieu
    //Dong tap tin lai
    ifstream fin;
    fin.open("Sach.txt");
    if(fin.is_open()){
        
        while(!fin.eof()){
            Sach s;
            fin>>s.maSach;
            fin.ignore();
//            fin.getline(s.maSach,5,'#');
            getline(fin, s.tenSach,'#');
            fin.getline(s.tenTacGia, 50, '#');
            fin>>s.giaBan;
            fin.ignore();
            fin>>s.giamGia;//int
//            fin.ignore();
            xuat1Sach(s);
            pushBackArr(l.ds, l.soLuong, s);
        }
        
        fin.close();
    }
}

//Yeu cau 3:
Sach* timKiem(DSQS l, char id[]){
    Sach *res = NULL;
    
    for(int i=0; i<l.soLuong;i++){
        if(strcmp(l.ds[i].maSach,id)==0){
            res = &l.ds[i];
            break;
        }
    }
    
    return res;
}

vector<Sach> timKiem(DSQS l, string name){
    vector<Sach> res;
    
    for(int i=0; i<l.soLuong;i++){
        if(l.ds[i].tenSach == name){
            res.push_back(l.ds[i]);
        }
    }
    
    return res;
}

//Yeu cau 4:
void addToCart(DSQS l, DSQS &cart){
    
    char id[5];
    int chon;
    
    do {
        cout << "Hay nhap ma sach can mua: ";
        cin >> id;//S005
        
        Sach*s = timKiem(l, id);
        if(s!=NULL){
            pushBackArr(cart.ds, cart.soLuong, *s);
        }else
            cout << "Khong co quyen sach can tim!\n";
        cout << "Them tiep tuc? (1-Yes, 0-No): ";
        cin >> chon;
    } while (chon!=0);
}

void xuatHD(DSQS cart){
    ofstream fout("HoaDon.txt");
    if(fout.is_open()){
        
        fout << tinhTongHD(cart) << endl;
        
        for(int i=0; i<cart.soLuong;i++){
            fout << cart.ds[i].maSach <<"#"<< cart.ds[i].tenSach << endl;
        }
        
        cout << "Da xuat hoa don thanh cong!\n";
        
        fout.close();
    }
}


int main(){
    DSQS l1;
    init(l1);
    readData(l1);
    xuatDsSach(l1);
    
//    cout << "========TIM KIEM========\n";
//    vector<Sach> res = timKiem(l1, "Dac Nhan Tam");
//    
//    
//    if(res.size()>0){
////        cout << res->tenSach << endl;
//        for(int i=0; i<res.size();i++)
//            xuat1Sach(res[i]);
//    }else
//        cout << "Khong tim thay!\n";
    
    cout << "========THEM VAO GIO HANG========\n";
    //Hoac dung vector
    DSQS cart;
    init(cart);
    
    addToCart(l1, cart);
    xuatDsSach(cart);
    
    xuatHD(cart);
    
    delete[]cart.ds;
    delete[]l1.ds;
    return 0;
}
