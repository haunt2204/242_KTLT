#include <iostream>
using namespace std;

class Diem {
private:
    int hoanhDo;
    int tungDo;
public:
        //Ham khoi tao
    Diem(int x, int y){
        hoanhDo = x;
        tungDo = y;
    }
        //Ham khoi tao khong tham so
    Diem(){
        
    }
    void setDiem(int x, int y);
    void nhapDiem();
    int getX(){
        return hoanhDo;
    }
    int getY(){
        return tungDo;
    }
    void print(){
        cout << "(" << hoanhDo<<","<<tungDo<<")";
    }
    double tinhKhoangCach(Diem d){
        return sqrt(pow(d.getX()-hoanhDo, 2) + pow(d.getY()-tungDo, 2));
    }
};

ostream& operator<<(ostream&out, Diem d){
    out << "(" << d.getX()<<","<<d.getY()<<")\n";
    return out;
}

void Diem::setDiem(int x, int y){
    hoanhDo = x;
    tungDo = y;
}

void Diem::nhapDiem(){
    cout << "Nhap hoanh do: ";
    cin >> hoanhDo;
    cout << "Nhap tung do: ";
    cin >> tungDo;
}
