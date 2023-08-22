#include <string>

using namespace std;

class SinhVien{
    public:
    static int MSSV;
    string TEN;
    string LOP;
};
int SinhVien::MSSV;

int main(){
    SinhVien sv1,sv2;
    printf("dia chi sv1:%p\n",&(sv1.MSSV));
    printf("dia chi sv2: %p\n",&(sv2.MSSV));

    return 0;
}