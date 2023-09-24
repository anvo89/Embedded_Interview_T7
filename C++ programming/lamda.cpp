#include<iostream>


int main(){

 /* auto func=[](){
        printf("hello\n");
        }
    func();
    */
int x=20;
double z=12.4;

auto tong=[=](int a,int b){
    printf("tong %d va %d\n,a,b,a+b");
    printf("x=%d\n",x);
    printf("x=%f\n",z);
};
tong(7,9);
    return 0;
}