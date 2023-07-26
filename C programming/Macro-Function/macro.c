#include <stdio.h>

#ifndef STM32
int a=10;
#endif;

#define SUM(a,b) a+b;
int main(){
    printf("tong a va b:%d\n",SUM(5,6));
    return 0;
}