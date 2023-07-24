#include <stdio.h>

int a=10;
void test(){
    printf("this is test\n");
}
int main()
{
    int*ptr=&a;
    printf("dia chi a: %p\n",&a);
    printf("gia tri cua ptr %p\n",ptr);
    printf("gia tri cua dia chi %d\n",*ptr);
    return 0;
}
