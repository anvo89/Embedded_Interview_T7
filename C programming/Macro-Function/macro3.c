#include <stdio.h>
#include<stdint.h>

#define CREATE_FUNC(func_name,cmd)   \
void func_name(){                       \
    printf(cmd);                        \
}

CREATE_FUNC(funcA,"This is function A\n");
int main(){
    funcA();
    return 0;
}