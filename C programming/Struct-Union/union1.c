#include <stdio.h>
#include<stdint.h>

typedef union 
{
   uint8_t var1;
   uint16_t var2[10];
   uint32_t var3;
}typeUnion;

int main()
{
    typeUnion var;
    printf("dia chi var:%p\n",&var);
    printf("dia chi var1:%p\n",&(var.var1));
    printf("dia chi var2:%p\n",&(var.var2));
    printf("dia chi var3:%p\n",&(var.var3));
   

   for (int i=0;i<5;i++)
   {
    var.var1[i]=i
   }
   for (int i=0;i<3;i++)
   {
    var.var2[i]=i*2;
   }
   for (int i=0;i<6;i++){
   var.var3[i]=i*3;}
   for (int i=0;i<5;i++)
   {
    printf("%d",var.var1[i]);
   }
    
    return 0;
}
