#include <iostream>

using  namespace std;

class DoiTuong{
    protected:
        string TEN;  //property
        int TUOI;  //property
    public:
    void nhapThongTin(string ten,int tuoi);  //method
    void hienThi(){
        cout<<"Ten: "<<TEN<<endl;
        cout<<"Tuoi : "<<TUOI<<endl;
    }
};
class SinhVien: public DoiTuong{
    private:
        int MSSV;
    public:                 // ghi đè
        void nhapThongtin(string ten,int tuoi,int MSSV);
};
void DoiTuong::nhapThongTin(string ten,int tuoi){
    this->TEN=ten;
    this->TUOI=tuoi;
}
int main(){
    DoiTuong dt;   //dt là object
    dt.nhapThongTin("Hoang",20);
    dt.hienThi();
    SinhVien sv;
    sv.nhapThongTin("Tuyet",20);
    sv.hienThi();

    return 0;
}
