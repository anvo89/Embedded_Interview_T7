#include<stdio.h>

void test()
{
    static int a=10; //Oxc1 , static cục bộ
    printf("a=%d\n",a);
    a++;
}

int main()
{
    test();
    test();
    test();
    return 0;
}