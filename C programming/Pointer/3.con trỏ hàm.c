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
int main()
{
    void (*ptr)(int,int);
    ptr=&tong;
    ptr(8,7);
    ptr=&hieu;
    ptr(9,4);
    int(*ptrTich)(int,int)=&tich;
    printf("tich %d\n",ptrTich(6,5));
    tinhToan(&tong,4,9);
    return 0;
}