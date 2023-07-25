#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start,end;
    double test;
    int i;
    start = clock();
    for (int i=0;i<100000;i++);
    end=clock();
    test=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time: %f\n",test);
    return 0;
    
}