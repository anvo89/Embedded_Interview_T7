#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int main()
{
    uint8_t *ptr=(uint8_t*)malloc(sizeof(uint8_t)*5);
    for (int i=0;i<5;i++)
    {
        ptr[i]=2*i;
    }
    for (int i=0;i<5;i++)
    {
        printf("i=%d\n",ptr[i]);
    }

    ptr=(uint8_t*)realloc(ptr,sizeof(uint8_t)*7); // từ 5 ô nhớ tăng lên 7 ô nhớ
   for (int i=0;i<7;i++)
    {
        ptr[i]=3*i;
    }
    for (int i=0;i<7;i++)
    {
        printf("i=%d\n",ptr[i]);
    }
    free (ptr); // thu hồi vùng nhớ
    return 0;

}