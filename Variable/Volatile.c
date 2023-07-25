#include <stdio.h>

int main()
{
    int test;
    volatile int test; // thông báo compiler test ko đc phép tối ưu
    while(1)
    {
        test=10;
        A();
        B();
        C();
    }
    return 0;
}