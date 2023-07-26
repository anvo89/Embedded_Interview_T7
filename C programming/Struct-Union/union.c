#include <stdio.h>
#include <stdint.h>

typedef union{
    uint8_t x;  //1
    uint16_t y[10];// 3 lần quét 8 byte =24
    uint64_t k;   //8   
}toaDo;

int main(){
  printf("size: %lu\n", sizeof(toaDo));
  return 0;
}