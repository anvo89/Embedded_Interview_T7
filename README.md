# Embedded_Interview_T7
## C programming 
### Pointer
1. Con trỏ là gì? Con trỏ trong C cũng chỉ là là biến, cũng có thể khai báo, khởi tạo và lưu trữ giá trị và có địa chỉ của riêng nó
* Giá trị của con trỏ: địa chỉ mà con trỏ trỏ đến.
* Địa chỉ của con trỏ: địa chỉ của bản thân biến con trỏ đó.
* Giá trị của biến nơi con trỏ đang trỏ tới.
* Địa chỉ của biến nơi con trỏ đang trỏ tới = giá trị của con trỏ.
2. Cách khai báo con trỏ
  < kiểu dữ liệu > * <tên biến>
  ```
int *p_i; // khai báo con trỏ để trỏ tới biến kiểu nguyên
int *p, val; // khai báo con trỏ p kiểu int, biến val (không phải con trỏ) kiểu int
float *p_f; // khai báo con trỏ để trỏ tới biến kiểu thực
char *p_char; // khai báo con trỏ để trỏ tới biến kiểu ký tự
void *p_v; // con trỏ kiểu void 
```
Example:

địa chỉ a: Oxc1

giá trị a: 10

int *ptr=Oxc1;

&a= Oxc1;

output:

*Oxc1=10 ( lấy giá trị tại địa chỉ Oxc1)

*địa chỉ : lấy giá trị tại địa chỉ này
```C
#include <stdio.h>
int main(){
	int *ptr=&a;
	printf("dia chi a %p\n",&a);
	printf("gia tri ptr %p\n",ptr);
	printf("gia tri cua dia chi :d\n",*ptr);
return 0;
}
```
output:
dia chi a 0x100a1400

gia tri ptr 0x100a1400

gia tri cua dia chi : 10

**Con trỏ Void** : là một con trỏ tổng quát, nó không trỏ đến các đối tượng của bất kì kiểu dữ liệu nào

*Khai báo* : void *ptr;
```C
int n;
float f;
double d;

void *ptr;
ptr = &n; // ok
ptr = &f; // ok
ptr = &d; // ok
```
*Con trỏ kiểu void cần phải được ép kiểu một cách rõ ràng sang con trỏ có kiểu dữ liệu khác trước khi sử dụng toán tử derefernce ()*
```C
printf("test i=%d\n",(int*)ptr); //ép kiểu ptr về int
```
nếu muốn lấy giá trị tại địa chỉ
```C
printf("test i=%d\n",*(int*)ptr);  
```
**Con trỏ hàm** :là một biến lưu trữ địa chỉ của một hàm, thông qua biến đó, có thể gọi hàm mà nó trỏ tới.

**<kiểu trả về> (*<tên con trỏ>)(<danh sách đối số>);**

*Ví dụ về con trỏ hàm nhận vào một biến kiểu int và trả về dữ liệu kiểu void*
```C
void (*func)(int);
```
```C
int main(){
	void (*ptr)(int,int);
	ptr= &tong;
	ptr(8,7);
	ptr=&hieu;
	ptr(9,4);
void tinhtoan(void (*func(int,int),int a,int b){
printf("tinh toan\n");
func(a,b);
```
```C
int main(){
	void *ptr[]={&tong,&hieu,&tich};
	((void(*)(int,int)ptr[2])(7,5)
return 0;
}
```
**Con trỏ NULL** : khi khai báo 1 con trỏ phải gán địa chỉ cho nó, nếu khai báo chưa sử dụng thì khai báo con trỏ NULL ( dc =0, giá trị =0), không gán trị cho nó thì nó sẽ trỏ đến giá trị rác.
*Chú ý: Nên khởi tạo con trỏ là null nếu nó chưa trỏ đến một địa chỉ cụ thể nào khác.*





