#include <stdio.h>

#define SIZE 10
#if SIZE>20
int a=30;
#elif SIZE==20
int a=20;
#else int a=10;
#endif

#define SUM(a,b) a+b;
int main(){
    printf("tong a va b:%d\n",SUM(5,6));
    return 0;
}