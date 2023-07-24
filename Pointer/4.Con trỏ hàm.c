include <stdio.h>

void tong(int a,int b)
{
    printf("tong %d va %d = %d\n",a,b,a+b);
}
void hieu(int a,int b)
{
    printf("hieu %d va %d :%d\n",a,b,a-b);
}
int tich(int a,int b){
    return a*b;
}
void tinhToan(void(*func)(int,int),int a,int b){
    printf("Tinh toan\n");
    func(a,b);
}
// sử dụng con trỏ hàm làm input parameter
int main(){
    void *ptr=&tong;
    ((void(*)(int,int))ptr)(8,9);
    //1. ép kiểu về con trỏ hàm void(*)(int,int)
    // để hàm hđ đc thì (void(*)(int,int)ptr)(9,5)
    // void *ptr[]=(&tong,&hieu,&tich);
    // (void(*)(int,int))ptr[2])(7,5)
}