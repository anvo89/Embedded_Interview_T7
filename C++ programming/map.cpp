#include <iostream>
#include <map>

using namespace std;

typedef struct{
    string ten;
    int tuoi;
}ThongTin;


int main(){
    map<int, ThongTin> SinhVien;
    SinhVien[101]={"Hoang",20};
    SinhVien[102]={"Tuan",18};
    SinhVien[103]={"Quan",21};

    for(auto item:SinhVien){
        cout<<"ID= "item.first<<"",Ten:"<<item.second.ten"<<",Tuoi:"<<item.second.tuoi<<endl;
        
    }

    return 0;
}