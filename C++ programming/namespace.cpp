#include <iostream>
#include "test.cpp"

using namespace std;

namespace ConOngA{
    int Teo=20;

}
namespace ConOngB{
    int Teo=30;
}


int main(){
    ConOngA::Teo=50;

    cout<<ConOngA::Teo<<endl;
    cout<<ConOngB::Teo<<endl;

    ConOngA::SinhVien sv;
    sv.TEN=20;
    
    return 0;
}