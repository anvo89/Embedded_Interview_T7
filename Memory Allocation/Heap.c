#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t array[]={1,7,3,5,9}; // mảng là những địa chỉ liền kề
    uint32_t *ptr=array;
    for (int i=0;i<5;i++){
    printf("dia chi :%p\n",*(ptr+i));}
    return 0;
}