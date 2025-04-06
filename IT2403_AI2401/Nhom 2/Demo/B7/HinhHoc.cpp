#include "TamGiac.h"


int main(){
    Diem dA(4,0);
    Diem dB(4,4);
    Diem dC(4,1);
    
    TamGiac tg(dA, dB, dC);
    
//    tg.nhapTg();
    tg.print();
    
    cout << "Kiem tra tam giac: " << tg.isTamGiac() << endl;
    cout << "Chu vi: " << tg.tinhChuVi() << endl;
    cout << "Dien tich: " << tg.tinhDienTich() << endl;
    
    return 0;
}


