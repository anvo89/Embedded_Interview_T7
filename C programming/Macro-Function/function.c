#include <stdio.h>

void tong(int a,int b)         //0x01--- 0x09
{
    printf("tong va b:%d\n",a+b);
}

int main()
{
    int a=5;//0x01
    int b=6;//0x02
    a=a-b;//0x03
    tong(9,5);
    tong(6,4);
    return 0;
}