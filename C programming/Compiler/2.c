#include <stdio.h>
#include "tesst.c"

#define SIZE 20
#define SUM(a,b)  a+b
int var=10;
void funcA()
{
    A();
    B();
    C();
    }
int main()
{   
    tesst();
    //array
    int array[SIZE];
    printf("Tong a va b %d\n",SUM(5,6));
    return 0;
}