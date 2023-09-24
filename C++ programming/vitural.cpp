#include<iostream>
#include"test.cpp"

class DoiTuong{
    public:
    virtual char *cmd(){
        return (char*)"DoiTuong\n";
    }
    void display(){
        printf("%s",cmd());
    }
};
class SinhVien:public DoiTuong{
    char *cmd(){        //load lai : overload
        return (char*)"SinhVien\n";
    }
};

int main(){
    DoiTuong dt;
    dt.display();
    SinhVien sv;
    sv.display();

    return 0;
}