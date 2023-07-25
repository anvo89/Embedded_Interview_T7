#include <stdio.h>

extern void test();
extern int count; // lấy biến count từ file test qua
int main()
{

    test();
    count=50;
    test();
    printf("test %d\n",count);
    return 0;

}