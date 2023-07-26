#include<stdio.h>
#include<stdint.h>

#define FUNC(...)  _VA_ARGS__

int main(){
    FUNC(test,"Hello world",15);
    return 0;
}