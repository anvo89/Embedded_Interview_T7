#include <iostream>
#include <string>

using namespace std;

class ToanHoc{                  //tính đa hình , những method có thể trùng tên nhau, căn cứ vào input parameter để nó chọn method
    public:
        void tong(int a,int b){
            cout<<"tong a va b: "<<a+b<<endl;
        }
        void tong(int a,int b,int c){
            cout<<"tong abc : "<<a+b+c<<endl;
    
        }
};

int man(){
    ToanHoc th;
    th.tong(8,3);
    th.tong(8,3,2);

    return 0;
}