# Embedded_Interview_T7

<details>
<summary> C programming </summary>

##
 <details>
	<Summary>Con trỏ </Summary>
		
	
### **1. Con trỏ là gì?** 

Là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.

 * Giá trị của con trỏ: địa chỉ mà con trỏ trỏ đến.

 * Địa chỉ của con trỏ: địa chỉ của bản thân biến con trỏ đó.

 * Giá trị của địa chỉ  = giá trị của biến
   
*Kích thước của các biến con trỏ có khác nhau không?*

Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:

- Môi trường Windows 32 bit: 4 bytes
 
- Môi trường Windows 64 bit: 8 bytes

### **2. Cách khai báo con trỏ**
  < kiểu dữ liệu > * <tên biến>
  ```
int *p_i; // khai báo con trỏ để trỏ tới biến kiểu nguyên
int *p, val; // khai báo con trỏ p kiểu int, biến val (không phải con trỏ) kiểu int
float *p_f; // khai báo con trỏ để trỏ tới biến kiểu thực
char *p_char; // khai báo con trỏ để trỏ tới biến kiểu ký tự
void *p_v; // con trỏ kiểu void 
```
***Example:***

	địa chỉ a: Oxc1

	giá trị a: 10

	int *ptr=Oxc1;

	&a= Oxc1;

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

### Hằng con trỏ

```<Kiểu dữ liệu> * const <Tên con trỏ> = <Địa chỉ khởi tạo> ;```

*Đặc điểm:*
– Cần gán ngay giá trị địa chỉ khởi tạo cho hằng con trỏ tại câu lệnh khai báo ban đầu.

– Không thể thay đổi địa chỉ đã được khởi gán cho hằng con trỏ ( sẽ gây ra lỗi).

– Có thể thay đổi giá trị tại địa chỉ đã khởi gián ban đầu.


### Con trỏ hằng

```const <Kiểu dữ liệu> * <Tên con trỏ>;```

*Đặc điểm:*

– Không được phép dùng trực tiếp con trỏ hằng để thay đổi giá trị tại vùng nhớ mà con trỏ hằng đang trỏ đến.

– Con trỏ hằng có thể thể thay đổi địa chỉ trỏ tới (hay nói cách khác: nó có thể trỏ đến các ô nhớ khác nhau).

[Link tham khảo](https://deviot.vn/tutorials/c-co-ban.78025672/con-tro-hang-va-hang-con-tro.06982839)

### **Con trỏ Void** 

Nó có thể lưu trữ địa chỉ của mọi kiểu biến dữ liệu

*Khai báo* : ```C void *ptr;```
```C
int n;
float f;
double d;

void *ptr;
ptr = &n; // ok
ptr = &f; // ok
ptr = &d; // ok
```
*Con trỏ kiểu void cần phải được ép kiểu để có thể đọc được giá trị tại địa chỉ đó*
```C
printf("test i=%d\n",(int*)ptr); //ép kiểu ptr về int
```
nếu muốn lấy giá trị tại địa chỉ
```C
printf("test i=%d\n",*(int*)ptr);  
```
### **Con trỏ hàm** 
Là một biến lưu trữ địa chỉ của một hàm, thông qua biến đó, có thể gọi hàm mà nó trỏ tới.

```**<kiểu trả về> (*<tên con trỏ>)(<danh sách đối số>);**```

*Ví dụ về con trỏ hàm nhận vào một biến kiểu int và trả về dữ liệu kiểu void*
```C
void (*func)(int);
```
```C
void tong(int a,int b)
{
    printf("tong %d va %d = %d\n",a,b,a+b);
}
int main()
{
    void (*ptr)(int,int);
    ptr=&tong;
    ptr(8,7);
```

### **Con trỏ NULL** 
Khi khai báo 1 con trỏ phải gán địa chỉ cho nó, nếu khai báo chưa sử dụng thì khai báo con trỏ NULL ( địa chỉ =0, giá trị =0), không gán trị cho nó thì nó sẽ trỏ đến giá trị rác.

*Chú ý: Nên khởi tạo con trỏ là null nếu nó chưa trỏ đến một địa chỉ cụ thể nào khác.*

### **Con trỏ trỏ đến con trỏ (Pointers to pointers)** 
là một con trỏ chứa địa chỉ của một con trỏ khác.
```C
int **ptr_ptr; // con trỏ trỏ đến con trỏ trỏ đến giá trị kiểu int 
```

</details>

##
<details>
	<summary>Phân vùng bộ nhớ trên RAM </summary>

##
 
<img src="https://2.bp.blogspot.com/-X1QjAlJ3fq4/VX7vg7FcrjI/AAAAAAAAAJs/U79uRx0Af_o/s1600/memory_layout.png">

##

### **1. Phân vùng bộ nhớ trên RAM**
	
### **Text :**  

- Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

- Chứa khai báo hằng số trong chương trình (.rodata)

### **Data:**

- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

- Được giải phóng khi kết thúc chương trình.

### **Bss:**

- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

- Được giải phóng khi kết thúc chương trình.

### **Stack:**

- Quyền truy cập là read-write.

- Được sử dụng cấp phát cho biến local, input parameter của hàm,…

- Sẽ được giải phóng khi ra khỏi block code/hàm

### **Heap:**

- Quyền truy cập là read-write.

- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …

- Sẽ được giải phóng khi gọi hàm free,…

### **2. Stack và Heap?**

• Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.

* Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào. Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
* Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C) 

  **Kích thước vùng nhớ**

* Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ 
điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy 
thuộc vào kiến trúc hệ điều hành của bạn).

* Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được 
nhu cầu lưu trữ dữ liệu của chương trình.

  **Đặc điểm vùng nhớ**
  
* Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự 
động hủy khi hàm thực hiện xong công việc của mình.

* Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong 
Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng 
nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy 
ra hiện tượng rò rỉ bộ nhớ. 

*Lưu ý: việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.*

  **Vấn đề lỗi xảy ra đối với vùng nhớ**
  
* Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ 
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

- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng 
nhớ Heap (Heap overflow).

- Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần 
được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
```C
int *A = (int *)malloc(18446744073709551615);
```
### **3. Cấp phát bộ nhớ động trong C : Malloc vs Calloc**

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
ptr=(uint16_t*)realloc(ptr,sizeof(uint16_t)*c7);
```
free : thu hồi vùng nhớ.
```C
void free(void *ptr);
```
</details>

##
<details>
<summary>Biến</summary>

Biến static được cấp phát bộ nhớ trong data segment

### Biến cục bộ là gì?

Các biến được khai báo trong 1 khối code thuộc lớp lưu trữ tự động (automatic or local variable) – hay chính là các biến cục bộ. Các biến cục bộ này chỉ tồn tại và chỉ có thể sử dụng bên trong khối code đó trong khi khối code đó đang thực thi.

### Biến toàn cục là gì?

Các biến được khai báo ở bên ngoài tất cả các hàm thì được gọi là biến toàn cục (external  or global variable). Các biến toàn cục có thể truy xuất và sử dụng ở mọi hàm trong chương trình. Biến toàn cục cũng tồn tại cho tới khi chương trình kết thúc.

### ***1. Biến static cục bộ***

Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
```C
Ví dụ:

#include<stdio.h>
 
int in_so_thu_tu(void)
{
   static int x = 0;
   x = x + 1;
   printf("%d\r\n",x);
} 
 
int main() {
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 0
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 1
   in_so_thu_tu ();         //giá trị của x tăng lên 1 đơn vị từ 2
   return 0;
}
```
Kết quả:
1
2
3
4
5

### ***2. Biến static toàn cục***
Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
```C
// biến a này chỉ được sử dụng trong file A.c
static int a;    

// hàm hienthi() này chỉ được sử dụng trong file A.c
static void hien_thi() {};   
```
 Ví dụ trong chương trình dưới đây, giá trị của x được in là 0, trong khi giá trị của y là giá trị rác.
```C
#include <stdio.h>
int main()
{
	static int x;
	int y;
	printf("%d \n %d", x, y);
}
```
Output

0

[some_garbage_value]

### ***3. Extern***
dùng để lấy hàm/biến có sẵn của các file khác cùng 1 Folder để sử dụng (trừ static)

Cú pháp: 

``` extern <kiểu dữ liệu> <Tên Biến>;```
*Ví dụ*
```C
#include<stdio.h>  //file test.c

int count=10;

void test()
{
    printf("count=%d\n",count);
    count++;
}
```
```C
#include <stdio.h>  //file extern.c
extern void test();

int main()
{

    test();
    return 0;

}
```

Để gộp 2 file lại : ```gcc extern.c test.c -o main```
		    ```./main```

### ***4. Volatile***

*Một biến cần được khai báo dưới dạng biến volatile khi nào?* 

Khi mà giá trị của nó có thể thay đổi một cách không báo trước. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.

Cú pháp: ```volatile <kiểu dữliệu> <tên dữ liệu>;```

### ***5. Biến register***

Làm tăng hiệu năng(performance) của chương trình.

*Với khai báo biến thông thường, để thực hiện một phép tính thì cần có 3 bước:*

* Nạp giá trị từ vùng nhớ chứa biến vào register
  
* Yêu cầu ALU xử lý register vừa được nạp giá trị
  
* Đưa kết quả vừa xử lý của ALU ra ngoài vùng nhớ chứa biến.

<img src="https://khuenguyencreator.com/wp-content/uploads/2021/09/register-.jpg">



</details>

##
<details>
	<summary> STRUCT&UNION  </summary>
	
### **1.STRUCT**

	
*Cú pháp định nghĩa struct*

```C
struct structureName 
{
    dataType member1;
    dataType member2;
    ...
};
```
* Sử dụng `.` => Toán tử truy xuất tới thành viên khi khai báo biến bình thương.
* Kích thước của struct phụ thuộc vào data alignment và data padding.
```C
struct number{ 
char a; //4byte
int b;  //4byte
char c;  /4byte
}mynum;
// bộ nhớ là 12 bytes//
```
### **2. UNION**

Cấu trúc của Union là tất cả các thành phần của nó dùng chung bộ nhớ, cho phép lưu trữ nhiều kiểu dữ liệu khác nhau trong cùng một vị trí bộ nhớ. Size của Union bằng size của thành phần lớn nhất trong Union

```C
union UnionName
{
	type attribute1;
	type attribute2;
	type attribute3;
	.... ..........;
};
```
```C
typedef union{
    uint8_t x;  //
    uint16_t y;//
    uint64_t k;   //  
}toaDo; 	//sizeof toaDo 8byte
```
### ***So sánh struct và union***

Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

•	**Struct**: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding). Tại 1 thời điểm run time có thể truy cập các thành phần của struct.

•	**Union**: Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác. Tại 1 thời điểm run time chỉ có thể truy cập 1 thành phần.

</details>

##
<details>
	<summary> Quá trình trình biên dịch </summary>
<img src="https://tapit.vn/wp-content/uploads/2017/07/GCC_CompilationProcess.png">
 
*Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:*

- Giai đoàn tiền xử lý (Pre-processor)
  
- Giai đoạn dịch NNBC sang Asembly (Compiler)
  
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
  
- Giai đoạn liên kết (Linker)
  
### **Quá trình trình biên dịch**
  
***1. Giai đoạn tiền xử lý – Preprocessor***
     
Giai đoạn này sẽ thực hiện:

- Nhận mã nguồn
  
- Xóa bỏ tất cả chú thích, comments của chương trình
  
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý

	+ Chỉ thị bao hàm tệp (#include).

	+ Chỉ thị định nghĩa cho tên (#define macro).

	+ Chỉ thị biên dịch có điều kiện (#if, #else, #elif, #endif, …).
  
*Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.*

***Note***

Sự khác nhau giữa #include <filename> and #include “filename” nằm ở khâu tìm kiếm file header của tiền xử lý trước quá trình biên dịch.

**#include <filename>**: tiền xử lý (pre-processor) sẽ chỉ tìm kiếm file header (.h) trong thư mục chứa file header của thư viện ngôn ngữ C (thường là thư mục trong bộ cài IDE).

**#include “filename”**: Trước tiên, tiền xử lý (pre-processor) tìm kiếm file header(.h) trong thư mục đặt project C/C++. Nếu không tìm thấy, tiền xử lý tìm kiếm file header (.h) trong thư mục chứa file header của thư viện ngôn ngữ C (thường là thư mục trong bộ cài IDE).
      

***2. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly***

- Phân tích cú pháp (syntax) của mã nguồn NNBC
  
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
  
***3. Công đoạn dịch Assembly***

- Dich chương trình => Sang mã máy 0 và 1
  
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó
  
***4. Giai đoạn Linker***

Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.

Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
</details>

##
<details>
	<summary> Macro - Function </summary>

### Chỉ thị biên dịch có điều kiện

**ifndef ( if not define )**

#ifndef identifier

     //Đoạn chương trình 1

#else

     //Đoạn chương trình 2

#endif

 Các chỉ thị điều kiện ở trên, thường được sử dụng cho việc xử lý xung đột thư viện khi chúng ta #include nhiều thư viện. 

 **#if, #elif, #else**

Cú pháp:

```C

#if constant-expression_1

// Đoạn chương trình 1

#elif  constant-expression_2

// Đoạn chương trình 2

#else

//Đoạn chương trình 3

#endif
```

Nếu constant-expression_1 true thì chỉ có đoạn chương trình 1 sẽ được biên dịch, trái lại nếu constant-expression_1 false thì sẽ tiếp tục kiểm ta đến constan-expression_2. Nếu vẫn chưa đúng thì đoạn chương trình trong chỉ thị #else được biên dịch .

Các constant-expression là biểu thức mà các toán hạng trong đó đều là hằng, các tên đã được định nghĩa bởi các #define cũng được xem là các hằng.

## Sự khác nhau giữa Macro, Inline và Function
### 1. Macro:
•	Được xử lý bởi preprocessor

•	Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó

•	VD: #define SUM(a,b)     (a+b)

•	Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

### 2. Inline
•	Được xử lý bởi compiler

•	Được khai báo với từ khóa inline

•	Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile.
	
### 3. Hàm bình thường
•	Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.

•	Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function).

### 4. So sánh
•	Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch.

•	Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi

•	Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình

•	Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.

•	Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình

•	Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.

[Các câu hỏi phỏng vấn tham khảo](https://deviot.vn/blog/tuyen-tap-cac-cau-hoi-phong-van-c-phan-1.17500622)

</details>
</details>
	
</details>

##
<details>
<summary>C++ programming</summary>	

 ##
 <details>
	<Summary>Cout,Cin,Endl  </Summary>

 ### I/O Library Header
 
 **iostream** : Nó được sử dụng để định nghĩa các đối tượng cout, cin và cerr tương ứng với luồng đầu ra tiêu chuẩn, luồng đầu vào tiêu chuẩn và luồng lỗi tiêu chuẩn tương ứng.

 ### Cout

**Cout** là một đối tượng được xác định trước của lớp ostream. Nó được kết nối với thiết bị đầu ra tiêu chuẩn, thường là màn hình hiển thị. Cout được sử dụng kết hợp với toán tử (<<) để hiển thị đầu ra trên console.

```C++
#include <iostream>
 
using namespace std;
 
int main() {
    char charArr[] = "Welcome to C++ tut!";  
    cout << "Value of charArr is: " << charArr << endl;  
}
```
### Cin

**cin** là một đối tượng được xác định trước của lớp istream. Nó được kết nối với thiết bị đầu vào tiêu chuẩn, mà thường là một bàn phím. Cin được sử dụng cùng với toán tử (>>) để đọc đầu vào từ console.
```C++
#include <iostream>
 
using namespace std;
 
int main() {
    int age; 
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age is: " << age << endl;
}
```
### Endl

**endl** là một đối tượng được xác định trước của lớp ostream. Nó được sử dụng để chèn một ký tự xuống dòng.
```C
#include <iostream>
 
using namespace std;
 
int main() {
    cout << "Learn";
    cout << " C++"<< endl;
    cout << "New line" << endl;
}
```		
</details>

 ##
 <details>
	<Summary> Class  </Summary>

## Class là gì?

**Class** hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho 
những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:

	* Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).

	* Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
 
	* Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt. 

Ví dụ về một class đơn giản, class Car. Một chiếc xe hơi vậy thì sẽ có chung những đặc điểm là đều có vô lăng, có bánh xe nhiều hơn 3, có động cơ… Đó là một class, 
một cái model hay mẫu mà người ta đã quy định là nếu đúng như vậy thì nó là xe hơi. Nhưng mà xe thì có thể có nhiều hãng khác nhau, BMW, Vinfast, Toyota… Thì 
mỗi hãng xe lại có những model xe khác nhau nhưng chúng đều là xe hơi. Vậy thì trong lập trình cũng vậy, class là quy định ra một mẫu, một cái model mà các thể 
hiện của nó (instance) hay đối tượng (object) phải tuân theo.

### Khai báo class và sử dụng class
```C
class Person {
 public:
 string firstName; // property
 string lastName; // property
 int age; // property
 void fullname() { // method
 cout << firstName << ' ' << lastName;
 }
}
```
## So sánh giữa Struct và Class

### Giống nhau:

Struct và Class đều có thể:

* Định nghĩa, khai báo các thuộc tính và hàm.
  
* Khai báo subscripts.

* Khai báo các initializers để khởi tạo.
  
* Có thể mở rộng bằng extension.
  
* Có thể implement các protocol để cung cấp các chức năng tiêu chuẩn.

### Khác nhau:

Initialize:

Khi định nghĩa 1 class, bạn bắt buộc phải khởi tạo 1 hàm init cho các thuộc tính không phải optional hoặc chưa có giá trị default.

```C
class Car {
    let id: Int = 1
    var color: UIColor?
    var price: Double
    
    init(price: Double) {
        self.price = price
    }
}

let car1 = Car(price: 5000)
```
Còn khi định nghĩa 1 struct, bạn không cần phải khởi tạo 1 hàm init bởi khi đó Struct đã tự định nghĩa 1 hàm init default cho bạn.
```C
struct Car {
    let id: Int = 1
    var color: UIColor
    var price: Double
}

let car1 = Car(color: .red, price: 5000)
```













