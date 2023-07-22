# Embedded_Interview_T7
## C programming
<details>
	<Summary> Con trỏ </Summary> 
	
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

**Con trỏ trỏ đến con trỏ (Pointers to pointers)** là một con trỏ chứa địa chỉ của một con trỏ khác.
```C
int **ptr_ptr; // con trỏ trỏ đến con trỏ trỏ đến giá trị kiểu int 
```
</details>
<details>
	<summary> Pointer</summary>

1. What is a pointer? Pointers in C are also just variables, can also declare, initialize and store values and have their own address.

* Pointer value: the address the pointer points to.
* Address of pointer: the address of the pointer variable itself.
* The value of the variable where the pointer is pointing.
* The address of the variable where the pointer is pointing = the value of the pointer.
2. How to declare pointers
   <data type> * <variable name>
   ```
int *p_i; // declare pointer to point to integer variable
int *p, val; // declare pointer p of type int, variable val (not pointer) of type int
float *p_f; // declare pointer to point to real variable
char *p_char; // declare pointer to point to character variable
void *p_v; // pointer of type void
```
Example:

address a: Oxc1

a value: 10

int *ptr=Oxc1;

&a= Oxc1;

output:

*Oxc1=10 (get value at address Oxc1)

*address : get value at this address
```C
#include <stdio.h>
int main(){
int *ptr=&a;
printf("dia to a %p\n",&a);
printf("value ptr %p\n",ptr);
printf("value of location :d\n",*ptr);
return 0;
}
```
output:
address 0x100a1400

value ptr 0x100a1400

the value of the address : 10

**Pointer Void** : is a general pointer, it does not point to objects of any data type

*Declaration* : void *ptr;
```C
int n;
float f;
double d;

void *ptr;
ptr = &n; // ok
ptr = &f; // ok
ptr = &d; // ok
```
*Pointers of type void need to be explicitly cast to pointers of other data types before using the derefernce()* operator.
```C
printf("test i=%d\n",(int*)ptr); // cast ptr to int
```
if want to get the value at address
```C
printf("test i=%d\n",*(int*)ptr);
```
**Function pointer** : is a variable that stores the address of a function, through which it is possible to call the function it points to.

**<return type> (*<pointer name>)(<argument list>);**

*Example of a function pointer that takes a variable of type int and returns void data*
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
void Tinhtoan(void (*func(int,int),int a,int b){
printf("calculate\n");
func(a,b);
```
```C
int main(){
void *ptr[]={&tong,&hieu,&tich};
((void(*)(int,int)ptr[2])(7,5)
return 0;
}
```
**NULL pointer** : when declaring a pointer, must assign an address to it, if the declaration is not in use, declare the pointer NULL ( dc =0, value =0), if you don't assign a value to it, it will point to a garbage value.

*Note: The pointer should be initialized to null if it does not already point to another specific address.*

**Pointers to pointers** is a pointer containing the address of another pointer.
```C
int **ptr_ptr; // pointer to pointer to value of type int
```
</details>
<details>
	<summary>Phân vùng bộ nhớ trên RAM </summary>




