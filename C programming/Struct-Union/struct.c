#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint8_t x[13]; //8byte + 8byte 1 padding
    uint16_t y[15];  //(2*4*3)+ 8 + 2 padding
    uint32_t z[10];//(4*2)*4 + 8+ 4 padding
    uint64_t k[3];    // 24 
}toaDo;

int main(){
  printf("size: %d\n", sizeof(toaDo));
  return 0;
}