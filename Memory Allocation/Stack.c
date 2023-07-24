#include <stdio.h>

void tong(int a,int b) // biến input parameter
{
    int c;  // biến cục bộ 
    c=a+b;
    printf("tong a va b:%d\n",a+b);
}
int main(){
    tong(6,9);
    tong(2,7);
    return 0;
}