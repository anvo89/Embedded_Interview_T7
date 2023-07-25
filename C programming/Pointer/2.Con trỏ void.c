#include <stdio.h>

void test()
{
    printf("this is test \n");
}

int main(){
    int i=10;
    double d=10.3;
    char c='A';
    void *ptr;
    ptr=&i;
    printf("test i= %d\n",*(int*)ptr);
    // ép kiểu int cho con trỏ void
    ptr=&d;
    printf("test d : %f\n",*(double*)ptr);
    ptr=&c;
    printf("test c : %c\n",*(char*)ptr);
    ptr=&test;
    return 0;
    
}