#include<stdio.h>

int count=10;
//static int count=10; chỉ sử dụng trong file này

void test()
{
    printf("count=%d\n",count);
    count++;
}