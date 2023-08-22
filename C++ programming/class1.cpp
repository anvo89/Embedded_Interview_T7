#include <iostream>
#include <string>

using namespace std;

class SinhVien{
    public:
        SinhVien(){
            static int id=1000;
            MSSV=id;
            id++;
        }
    int MSSV;
    string TEN;
    string LOP;
    int NAM_SINH;
}
int main(){
    SinhVien sv;

    sv.LOP="CDT12";
    sv.MSSV=100101;
    sv.NAM_SINH=2000s;
    sv.TEN="HOANG";

    cout<<"MSSV:"<<sv.MSSV<<endl;
    cout<<"TEN:"<<sv.TEN<<endl;
    cout<<"NAM SINH:"<<sv.NAM_SINH<<endl;
    cout<<"LOP:"<<sv.LOP<<endl;
    SinhVien sv2={1003,"Hoang","CDT32",1999};
    display sv1;
    display sv2;

    return 0;
} 