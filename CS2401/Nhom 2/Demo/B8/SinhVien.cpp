#include <iostream>
#include <fstream>
using namespace std;

#define SOMH 3

struct SinhVien {
    long long id;
    string hoTen;
    char queQuan[100];
    char ngaySinh[11];
    double diem[SOMH];
};

void print(SinhVien sv){
    cout << "==================\n";
    cout << "ID: " << sv.id << endl;
    cout << "Name: " << sv.hoTen << endl;
    cout << "Que quan: "<< sv.queQuan << endl;
    cout << "Ngay sinh: " << sv.ngaySinh << endl;
    cout << "Diem: ";
    for(int i=0;i<SOMH;i++){
        cout << sv.diem[i] << " ";
    }
    cout << "\n==============\n";
}

void pushBackArr(SinhVien *&a, int &n, SinhVien x){
    if(a==NULL){
        n = 1;
        a = new SinhVien[n];
        a[0] = x;
    }else{
        SinhVien *newArr = new SinhVien[n+1];
        
        for(int i=0; i<n;i++){
            newArr[i] = a[i];
        }
        
        newArr[n++] = x;
        
        delete [] a;
        
        a=newArr;
    }
}

void sort(SinhVien *ds, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ds[j].id<ds[i].id)
                swap(ds[j], ds[i]);
        }
    }
}

int main(){
    SinhVien *ds = NULL;
    int n;
    
    ifstream inFile("SinhVien.txt");
    
    if(inFile.is_open()){
        while(!inFile.eof()){
            SinhVien sv;
            
            inFile >> sv.id;
            inFile.ignore();
            getline(inFile, sv.hoTen);
            inFile.getline(sv.queQuan, 100);
            inFile>>sv.ngaySinh;
            for(int i=0;i<SOMH;i++){
                inFile>>sv.diem[i];
            }
            
            pushBackArr(ds, n, sv);
//            print(sv);
        }
        
        
        sort(ds, n);
        
        for(int i=0; i<n; i++){
            print(ds[i]);
        }
        
        
        inFile.close();
    }
    
    
    return 0;
}
