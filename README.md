# Embedded_Interview_T7
## C programming
<details>
<summary>Tiếng Việt</summary>
	<details>
		 <Summary>Con trỏ </Summary>
	
1. Con trỏ là gì? là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
* Giá trị của con trỏ: địa chỉ mà con trỏ trỏ đến.
* Địa chỉ của con trỏ: địa chỉ của bản thân biến con trỏ đó.
* Giá trị của biến nơi con trỏ đang trỏ tới.
* Địa chỉ của biến nơi con trỏ đang trỏ tới = giá trị của con trỏ.
  
*Kích thước của các biến con trỏ có khác nhau không?*

Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
* Môi trường Windows 32 bit: 4 bytes
* Môi trường Windows 64 bit: 8 bytes

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
	<summary>Phân vùng bộ nhớ trên RAM </summary>
<img src="https://i0.wp.com/media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg?resize=449%2C343&ssl=1">
	
**Text :**  

– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

– Chứa khai báo hằng số trong chương trình (.rodata)

**Data:**

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

– Được giải phóng khi kết thúc chương trình.

**Bss:**

– Quyền truy cập là read-write.

– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

– Được giải phóng khi kết thúc chương trình.

**Stack:**

– Quyền truy cập là read-write.

– Được sử dụng cấp phát cho biến local, input parameter của hàm,…

– Sẽ được giải phóng khi ra khỏi block code/hàm

**Heap:**

– Quyền truy cập là read-write.

– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

– Sẽ được giải phóng khi gọi hàm free,…

***2. Stack và Heap?***

• Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong 
RAM khi chương trình được thực thi.

• Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy 
cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.

• Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động 
bởi các hàm malloc - calloc - realloc (trong C)

  **Kích thước vùng nhớ**

Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ 
điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy 
thuộc vào kiến trúc hệ điều hành của bạn).

Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được 
nhu cầu lưu trữ dữ liệu của chương trình.

  **Đặc điểm vùng nhớ**
  
Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự 
động hủy khi hàm thực hiện xong công việc của mình.

Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong 
Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng 
nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy 
ra hiện tượng rò rỉ bộ nhớ. 

*Lưu ý: việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.*

  **Vấn đề lỗi xảy ra đối với vùng nhớ**
  
Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ 
vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack 
(Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ 
quy vô hạn,...

Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:
```C
 int foo(int x){
 printf("De quy khong gioi han\n");
 return foo(x);
}
```

Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng 
nhớ Heap (Heap overflow).

Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần 
được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
```C
int *A = (int *)malloc(18446744073709551615);
```
**Cấp phát bộ nhớ động trong C : Malloc vs Calloc**

Để cấp phát bộ nhớ động trong C, chúng ta có 2 cách:
```C
void* malloc (size_t size);
void* calloc (size_t num, size_t size);
```
 * Khi sử dụng malloc phải tính toán kích thước vùng nhớ cần cấp phát trước rồi truyền vào cho malloc.
 * Khi sử dụng calloc chỉ cần truyền vào số phần tử và kích thước 1 phần tử, thì calloc sẽ tự động tính toán và cấp phát vùng nhớ cần thiết.
   
 *Ví dụ: Cấp phát mảng 10 phần tử kiểu int:*
```C
int *a = (int *) malloc( 10 * sizeof( int ));
int *b = (int *) calloc( 10, sizeof( int ));
```
```C
uint8_t *ptr=malloc(5)       //5byte
uint8_t *ptr=(uint8_t*)malloc(5);
//( tăng bộ nhớ từ 1 byte lên 5byte)
unit16_t *ptr=(uint16_t*)malloc(sizeof(unit16_t)*5);

```
*Công thức của hàm realloc() trong C*
```C
void *realloc(void *ptr, size_t size)
ptr=(uint16_t*)realloc(ptr,sizeof(uint16_t)*7);
```
free : thu hồi vùng nhớ.
```C
void free(void *ptr);
```
</details>
<details>
<summary>Biến</summary>
..


</details>
</details>
<details>
<summary>English</summary>
<details>
	<summary>Memory Allocation </summary>
<img src="https://i0.wp.com/media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg?resize=449%2C343&ssl=1">

**Text :**

– Access is only Read and it does not contain instructions to execute, so avoid modifying the instruction.

– Contains declaration of constants in the program (.rodata)

**Data:**

* Access is read-write.

* Contains a global variable or a static variable with a non-zero initialized value.

* Released at the end of the program.

**Bss:**

* Access is read-write.

* Contains global or static variables with zero or zero initialization.

* Released at the end of the program.

**Stack:**

* Access is read-write.

* Used to allocate for local variables, input parameters of the function, etc.

* Will be released when exiting the code/function block

**Heap:**

– Access is read-write.

– Used to allocate dynamic memory such as: Malloc, Calloc, ...

– Will be released when calling the free…

***2. Stack and Heap?***

• Heap memory and Stack memory are essentially the same memory area created and stored in
RAM when the program is executed.

• Stack memory is used to store local variables in functions, parameters passed in... Access
This memory access is very fast and is executed when the program is compiled.

• Heap memory is used to store memory for dynamically allocated pointer variables
by functions malloc - calloc - realloc (in C)

   **Memory size**

Stack: The size of the Stack memory is fixed, depending on the operating system, for example,
Windows operating system is 1 MB, Linux operating system is 8 MB (note that the number may vary depending on
depending on your OS architecture).

Heap: The size of the Heap memory is not fixed, it can be increased or decreased so it is responsive
program data storage needs.

   **Memory features**
  
Stack: Stack memory is managed by the operating system, the data stored in the Stack will automatically
cancel when the function has done its job.

Heap: The memory area Heap is managed by the programmer (in C or C++), the data in
The heap will not be destroyed when the function is done, which means you have to manually destroy the area
remember with the free statement (in C), and delete or delete [] (in C++), otherwise it will happen
memory leak occurs.

*Note: automatic memory cleanup depends on intermediate compiler.*

   **The problem occurs with the memory area**
  
Stack: because Stack memory is fixed, if your program uses too much memory
If you exceed the storage capacity of the Stack, there will definitely be a Stack overflow
(Stack overflow), cases happen like you initialize too many local variables, file function
limitless,...

Example of Stack overflow with infinite recursion:
```C
  int foo(int x){
  printf("Determined without setting\n");
  return foo(x);
}
```

Heap: If you continuously allocate memory without freeing it, you will get an overflow error
Remember the Heap (Heap overflow).

If you initialize a memory area too large that the heap cannot store once
will be failed to initialize the Heap memory area.

Example case initialization of Heap memory is too large:
```C
int *A = (int *)malloc(18446744073709551615);
```
**Dynamic memory allocation in C : Malloc vs Calloc**

To allocate dynamic memory in C, we have 2 ways:
```C
void* malloc (size_t size);
void* calloc(size_t num, size_t size);
```
  * When using malloc, you must calculate the size of the memory to be allocated first and then pass it on to malloc.
  * When using calloc, just pass in the number of elements and the size of 1 element, then calloc will automatically calculate and allocate the necessary memory.
   
  *Example: Allocating a 10-element array of type int:*
```C
int *a = (int *) malloc( 10 * sizeof( int ));
int *b = (int *) calloc( 10, sizeof( int ));
```
```C
uint8_t *ptr=malloc(5) //5byte
uint8_t *ptr=(uint8_t*)malloc(5);
//(increase memory from 1 byte to 5byte)
unit16_t *ptr=(uint16_t*)malloc(sizeof(unit16_t)*5);

```
*Formula of realloc() function in C*
```C
void *realloc(void *ptr, size_t size)
ptr=(uint16_t*)realloc(ptr,sizeof(uint16_t)*7);
```
free : free memory.
```C
void free(void *ptr);
```
</details>
<details>
	<summary> Pointer</summary>

1. What is a pointer? Pointers in C are also just variables, can also declare, initialize and store values and have their own address.

* Pointer value: the address the pointer points to.
* Address of pointer: the address of the pointer variable itself.
* The value of the variable where the pointer is pointing.
* The address of the variable where the pointer is pointing = the value of the pointer.
2. How to declare pointers?
 ``` 
   <data type> * <variable name>
```
 ```C  
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
<summary>Variable</summary>
..
