#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void test1()
{
    uint8_t array[5];
    printf("dia chi:%p\n",array);
}

void test2()
{
    uint8_t *array=(uint8_t*)malloc(sizeof(uint8_t)*5);
    printf("dia chi %p\n",array);
    free(array);
}
int main()
{
    test1();
    test1();

    test2();
    test2();

    return 0;
}