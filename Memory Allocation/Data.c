#include <stdio.h>

int a=10; // biến toàn cục
static int b=20; //biến static toàn cục
void test(){
    static int c=30; //biến static cục bộ
}

// giá trị biến khởi tạo khác 0
int main()
{
    return 0;

}