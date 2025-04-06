#include "Diem.h"


class TamGiac {
private:
    Diem dA, dB, dC;
    double a, b, c;
    
    void tinhDoDai(){
        a = dA.tinhKhoangCach(dB);
        b = dB.tinhKhoangCach(dC);
        c = dA.tinhKhoangCach(dC);
    }
public:
    TamGiac(Diem d1, Diem d2, Diem d3){
        dA = d1;
        dB = d2;
        dC = d3;
        tinhDoDai();
    }
    
    TamGiac(){
        
    }
    
    bool isTamGiac(){
        if(a+b>c && a+c>b && b+c>a)
            return true;
        
        return false;
    }
    
    double tinhChuVi(){
        if(!isTamGiac())
            return -1;
        return (a+b+c);
    }
    
    double tinhDienTich(){
        if(!isTamGiac())
            return -1;
        
        double p = tinhChuVi()/2;
        
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    
    void nhapTg(){
        cout << "Nhap diem 1:\n";
        dA.nhapDiem();
        cout << "Nhap diem 2:\n";
        dB.nhapDiem();
        cout << "Nhap diem 3:\n";
        dC.nhapDiem();
        
        tinhDoDai();
    }
    
    void print(){
        cout << "(";
        dA.print();
        cout << ",";
        dB.print();
        cout << ",";
        dC.print();
        cout << ")\n";
    }
};
