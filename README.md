# Embedded_Interview_T7


<details>
<summary> <h1>C programming</h1> </summary>

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

<details>
  <summary><h2>Thao tác BIT</h2></summary>

**1. AND: x=y & z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/4792bda0-11e7-42ab-be91-24f3913a14cb)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/d3561b69-3f42-43be-882b-4521d221ab60)

**2. NOT: x=~y**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/171570a9-e47e-426f-b767-936f07b3da5c)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/bb83e7dd-62e9-42b4-88a4-eacea3ede919)

**3. OR: x=y | z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/38cba77d-f2be-4fc5-b936-8c19f6652cd0)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/2bba2c0c-d39c-4349-94a0-59f17229c219)

**4. XOR: x = y ^ z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/328b53db-f44c-4519-b35b-65275ce82205)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/62261a3f-24f3-452b-b13d-4322da32269b)
  
**5. Dịch Bit: >> (Dịch phải) và << ( Dịch trái )**
 
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/2e1f97a1-a4d2-4422-923c-546b76e0d9f7)
***
**:blue_square: Ví dụ: Giả sử có 1 vi điều khiển 8bit (1 lần quét điều khiển được 8 chân)**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/e7d842d4-46ba-405e-885c-79b5e9e6ab99)
* Xây dựng thuật toán set mức cao thấp tại các chân pin:

> Thuật toán set mức cao: PORTA=0b00000000
```
    PORTA = PORTA |(0b10000000 >> pin);
```

=> Giả sử set chân PIN4 về mức cao thì pin=5, 0b10000000 dịch sang phải 5 bit là: 0b00001000 rồi thực hiện phép OR với PORTA thì cho kết quả là: 0b00001000 (chân PIN4 đã set về mức cao).
> Thuật toán set mức thấp: PORTA=0b11111111
```
    PORTA = PORTA & ~(0b10000000 >> pin); 
```

=> Giả sử set chân PIN3 về mức thấp thì pin=4, 0b10000000 dịch sang phải 4 bit là: 0b00010000, NOT của 0b00010000 là 0b11101111 rồi thực hiện phép AND với PORTA thì cho kết quả là: 0b11101111 (chân PIN3 đã set về mức thấp).


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
<summary><h1>C++ programming</h1></summary>	

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
### Cú pháp tạo object của một class và sử dụng các thuộc tính và phương thức:

```C++
Person person;
person.firstName = "Khiem";
person.lastName = "Le";
person.fullname(); // sẽ in ra màn hình là "Khiem Le"
```

### Khi nào nên sử dụng struct / class?

***Recommend sử dụng struct bởi:***

Struct nhanh hơn class bởi struct sử dụng method dispatch là static dispatch, class sử dụng dynamic dispatch. Ngoài ra, struct lưu dữ liệu trong stack, còn class sử dụng stack + heap -> Xử lí trong class sẽ lâu hơn.

Class là 1 reference type. Do đó, nếu không cẩn thận khi truyền biến sẽ dễ gây ra lỗi ngoài ý muốn ( Xem phần value type vs reference type ở trên). -> Sử dụng struct sẽ an toàn hơn.

***Nên sử dụng class khi:***

* Cần sử dụng kế thừa.
  
* Cần sử dụng reference type (Thay vì việc tạo ra các bản sao, thì 1 instance kiểu reference type sẽ tự truyền đi 1 tham chiếu tới chính nó khi được gán cho các insstance khác hoặc khi được truyền vào hàm.)

[Link tham khảo](https://magz.techover.io/2020/03/01/su-khac-biet-giua-struct-va-class/)

## Hàm tạo, Hàm hủy (Constructor,Destructor)

**Constructor** hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object.


Constructor trong C++ có thể được chia thành 2 loại:

* Constructor mặc định.
* Constructor có tham số.

### Constructor mặc định

Một constructor không có đối số được gọi là constructor mặc định
```C++
#include <iostream>
 
using namespace std;
 
class Employee {
public:
    Employee() {
        cout << "Constructor mac dinh duoc goi..." << endl;
    }
};
 
int main(void) {
    Employee e1; //tao doi tuong Employee
    Employee e2;
    return 0;
}
```
### Constructor có tham số

Một constructor có tham số được gọi là constructor tham số hóa. Nó được sử dụng để cung cấp các giá trị khác nhau cho các đối tượng riêng biệt.

```C++
#include <iostream>
 
using namespace std;
 
class Employee {
public:
    int id; // data member (bien instance)
    string name; // data member(bien instance)
    float salary;
    Employee(int i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }
    void display() { cout << id << "  " << name << "  " << salary << endl; }
};
 
int main(void) {
    Employee e1 = Employee(101, "Phan Van Vinh", 500); // tao doi tuong Employee
    Employee e2 = Employee(102, "Dao Van Hoa", 1000);
    e1.display();
    e2.display();
    return 0;
}
```
### Destructor

Trong khi các hàm constructors (hàm khởi tạo) được thiết kế để khởi tạo một class, thì các hàm destructors (hàm hủy) được thiết kế để hỗ trợ việc dọn dẹp bộ nhớ.

Hàm hủy (Destructor) trong C++ được gọi tự động lúc đối tượng đi ra khỏi phạm vi:

* Kết thúc hàm
* Kết thúc chương trình
* Kết thúc 1 block
* Toán tử delete được gọi

Hàm hủy trong c++ có 3 tính chất như sau:

* Tên hàm hủy giống tên của class nhưng phải đặt kèm toán tử ~ đằng trước thành ~classname.
* Hàm hủy không mang kiểu dữ liệu trong nó, cũng như không sử dụng void khi khai báo nó.
* Hàm hủy không có tham số, cũng không trả về giá trị từ nó.

```C++

class MyClass {
public:
    MyClass();   // Hàm khởi tạo
    ~MyClass();  // Hàm hủy
};
```






## Phạm vi truy cập ( Access modifiers )

Access modifier là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là public, private và protected.
* Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính;
* Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
* Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

### Static member

Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong 
suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.

</details>

##
<details>
	<summary> OOP </summary>

 ## Đặc tính của lập trình hướng đối tượng

 
Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ mà chúng ta cần nắm vững sau đây:

### Inheritance (Tính kế thừa )

Trong lập trình hướng đối tượng có ý nghĩa, một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong C++.

***Cú pháp***
``C++
class <tên_class_con> : <phạm_vi_truy_cập> <tên_class_cha>
{
    // code goes here
};
```
Giả sử mình có một class A với các thuộc tính, phương thức bên trong. Mình muốn khai báo một class B kế thừa từ class A, mình sẽ có cú pháp như sau:
```C++
class B : public/private/protected A
{
    // code goes here
};
```
**public:**

* Các thuộc tính public của A sẽ trở thành thuộc tính public của B
* Các thuộc tính protected của A sẽ trở thành protected của B
  
**private:**

* Các thuộc tính public của A sẽ trở thành thuộc tính private của B
* Các thuộc tính protected của A sẽ trở thành private của B
  
**protected:**

* Các thuộc tính public của A sẽ trở thành thuộc tính protected của B
* Các thuộc tính protected của A sẽ trở thành thuộc tính protected của B


### Abstraction (Tính trừu tượng) 
Trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà 
gạo có thể nấu thành cơm

### Polymorphism (Tính đa hình)

Trong lập trình hướng đối tượng là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.

trong lập trình thuật ngữ này dùng để ám chỉ đến việc một biến, một hàm hoặc một phương thức có thể tồn tại ở nhiều dạng khác nhau. Tức là **nhiều hàm** hoặc **phương thức** có thể **cùng một tên** nhưng chức năng thực sự của chúng lại **khác nhau**.

```C++
#include <iostream>
using namespace std;
 
class inDuLieu 
{
   public:
      void hamIn(int i) {
        cout << "In so nguyen: " << i << endl;
      }

      void hamIn(double  f) {
        cout << "In so thuc: " << f << endl;
      }

      void hamIn(string s) {
        cout << "In chuoi: " << s << endl;
      }
};

int main(void)
{
   inDuLieu idl;
 
   // Goi ham hamIn de in so nguyen
   idl.hamIn(1235);
   // Goi ham hamIn de in so thuc
   idl.hamIn(67.02);
   // Goi ham hamIn de in chuoi
   idl.hamIn("Codelearn.io");
 
   return 0;
}
```

### Encapsulation (Tính đóng gói) 

Có thể nói tính đóng gói (Encapsulation) là cơ chế của che giấu dữ liệu (Data Hiding) bởi chúng được lớp (class) che giấu đi (ở dạng private) một số dữ liệu, hàm và phương thức để đảm bảo rằng các dữ liệu đó sẽ được truy cập và sử dụng đúng mục đích, đúng cách thông qua các hàm và phương thức ở dạng public mà class cung cấp. Đó là lý do bạn không thể truy cập đến các thuộc tính private hoặc gọi đến phương thức private của class từ bên ngoài class đó.

Tính đóng gói được thể hiện khi mỗi đối tượng mang trạng thái là *private* ở bên trong một class và những đối tượng khác không thể truy cập trực tiếp vào phạm vi này. Thay vào đó họ chỉ có thể gọi các hàm mang phạm vi public được gọi là phương thức.

**Ví dụ**
```C++
class Box
{
   public:
      double tinhTheTich(void)
      {
         return chieudai * chieurong * chieucao;
      }
   private:
      double chieudai;      // Chieu dai cua mot box
      double chieurong;     // Chieu rong cua mot box
      double chieucao;      // Chieu cao cua mot box
};
```
Các biến chieudai, chieurong, và chieucao là private. Nghĩa là chúng chỉ có thể được truy cập bởi các thành viên khác của lớp Box, và không thể bởi bất kỳ phần khác trong chương trình của bạn. Đây là một cách thực hiện tính đóng gói trong C++.






</details>

##

<details>
	<summary>VECTOR,THAM TRỊ, THAM CHIẾU</summary>

 ## VECTOR

Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector.Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình.
```C++
#include <vector>
//...
vector<object_type> variable_name;
```

**Modifiers**

1. push_back(): Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu của vector thì sẽ bị ném ra.
   
ten-vector.push_back(ten-cua-phan-tu);

2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
   
ten-vector.assign(int size, int value);

3. pop_back(): Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
   
4. insert(): Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.

5. erase(): Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
   
6. emplace(): Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
   
7. emplace_back(): Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
    
8. swap(): Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
    
9. clear(): Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector

## THAM CHIẾU , THAM TRỊ

### Tham chiếu (pass by reference)

Truyền tham chiếu chính là cách chúng ta truyền cho nó một bản gốc thông qua địa chỉ '&'. Ví dụ với hàm changeValue(int &x); thì đối số x ở đây lúc này là một tham chiếu.

Với cách truyền này dữ liệu của lời gọi có thể được sửa đổi bởi hàm được gọi.

### Tham trị (pass by value)

Truyền tham trị là truyền cho đối số một bản sao.

Khi dùng tham trị thì x ở hàm changeValue và ở main 2 biến là độc lập với nhau.

Khi dùng tham chiếu thì x ở hàm changeValue và ở main 2 biến là một.

[Link tham khảo](https://codelearn.io/sharing/tham-chieu-va-tham-tri-trong-cpp)
	
</details>

##

<details>
	<summary>Template, namespace, virtual function, linked list </summary>

##

## TEMPLATE

Trong C++, template là một tính năng mạnh mẽ cho phép bạn viết mã một lần và sử dụng nó cho nhiều kiểu dữ liệu khác nhau mà không cần viết lại mã cho mỗi kiểu dữ liệu đó. 

Ví dụ 1:
```C++
#include <iostream>

template <typename var>

var tong(var a,var b){
    return var(a+b);
}

int main(){
    printf("tong a va b:%d\n",tong(4,5));
    
    printf("tong a va b: %f\n",tong(4.3,5.2));
    return 0;
}
```
Ví dụ 2:
```C++
#include <iostream>

template <typename var1,typename var2>

var1 tong(var1 a,var2 b){
    return var1(a+b);
}

int main(){
    printf("tong a va b:%d\n",tong(4,5));
// 4 là int=> var 1 là int , 5 là int => var2 là int
    printf("tong a va b: %f\n",tong(4.3,5));

//4.3 var 1 là double, var 2 là int . ép kiểu cho var 1 theo double

    return 0;
}
```

##

## NAMESPACE

Namespace trong C++ giống như một hộp lưu trữ cho các biến và hàm. Có thể đặt tất cả các biến và hàm có liên quan vào trong hộp lưu trữ này, và có thể có nhiều hộp lưu trữ khác nhau cho các phần khác nhau của chương trình của mình. Như vậy, không phải lo lắng về việc xung đột tên giữa các phần khác nhau của chương trình.

**Cú pháp**
```C
namespace ten_namespace{
    //code
}
```
Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì vậy trình biên dịch chương trình sẽ báo lỗi.

***fileB***

```C++
#include <iostream>

using namespace std;

void function() { cout << “function in fileB running.” << endl; }
```
***fileC***
```C++
#include <iostream>

using namespace std;

void function(() { cout << “function in fileC running.” << endl; }
```
***FileA***
```C++
#include <iostream>
#incldue “fileB.hpp”
#include “fileC.hpp”

using namespace std;

int main() {
    fileB::function();
    fileC::function();
    
    return 0;
}
```
### VIRTUAL FUNCTION  ( HÀM ẢO )

Hàm ảo (virtual function) là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần phải định nghĩa lại.

Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có kiểu là lớp cơ sở trỏ đến đối tượng của lớp dẫn xuất.

**Vi du**

```C++
#include<iostream>
#include"test.cpp"

class DoiTuong{
    public:
    virtual char *cmd(){
        return (char*)"DoiTuong\n";
    }
    void display(){
        printf("%s",cmd());
    }
};
class SinhVien:public DoiTuong{
    char *cmd(){        //load lai : overload
        return (char*)"SinhVien\n";
    }
};

int main(){
    DoiTuong dt;
    dt.display();
    SinhVien sv;
    sv.display();

    return 0;
}
```
Trong trường hợp này ,*nếu không thêm virtual* phía trước **cmd**  thì khi gọi sv.display() output sẽ hiển thị *DoiTuong* vì nó đang kế thừa lớp DoiTuong. *Khi thêm virtual* vào trước **cmd** , khi nó chạy cmd nó sẽ là overload thì nó sẽ load cái mới nhất (cmd định nghĩa sau cùng). 

##

### LINKED LIST

Một Danh sách liên kết (Linked List) là 1 dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Hiểu một cách đơn thuần thì Danh sách liên kết là một cấu trúc dữ liệu bao gồm 1 nhóm những nút (node) tạo thành 1 chuỗi. Mỗi nút gồm dữ liệu ở nút ấy và tham chiếu đến nút kế tiếp trong chuỗi.

<img src="https://techacademy.edu.vn/wp-content/uploads/2021/10/Linked-List-C-La-Gi.png">

Do danh sách liên kết đơn là một cấu trúc dữ liệu động, được tạo nên nhờ việc cấp phát động nên nó mang một số đặc điểm sau đây:

* Được cấp phát bộ nhớ khi chạy chương trình
* Có thể đổi thay kích thước qua việc thêm, xóa phần tử
* Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM
* Các phần tử được lưu trữ tự nhiên (không liên tiếp) trong RAM

### Sự khác nhau giữa LinkedList và ArrayList

Sự khác nhau lớn nhất giữa ArrayList và LinkedList nằm ở chỗ có cấu trúc dữ liệu khác, nếu bạn hiểu được cấu trúc của 2 ArrayList và LinkedList thì những khác biệt dưới đây sẽ rất dễ hiểu:

* Array là cấu trúc dữ liệu có chỉ mục(index) nên tìm kiếm trên Array nhanh hơn, độ phức tạp khi tìm kiếm một phần tử trong Array là O(1). Trái lại, với LinkedList chúng ta không thể truy cập phần tử theo chỉ mục hoặc ngẫu nhiên mà phải duyệt qua các phần tử nên độ phức tạp là O(n)

* Chèn phần tử mới vào LinkedList dễ dàng và nhanh hơn so với ArrayList vì LinkedList không có rủi ro về thay đổi kích thước và sao chép dữ liệu sang mảng mới nếu mảng đầy chỉ với độ phức tạo O(1), nhưng với ArrayList thì rất hạn chế để thực hiện thêm mới và sao chép dữ liệu khi đầy thì độ phức tạp là O(n). Bên cạnh đó, ArrayList cần cập nhật lại chỉ mục nếu thêm một phần tử vào giữa mảng.

* Xóa phần tử trong mảng giống như thêm mới thì LinkdedList có hiệu suất tốt hơn ArrayList.

* LinkedList chiếm nhiều bộ nhớ hơn ArrayList vì trong ArrayList mỗi phần tử chỉ chứa một đối tượng dữ liệu còn LinkedList thì mỗi phần tử(node) lại chứa dữ liệu và địa chỉ của phần tử trước và phần tử sau.

### Khi nào dùng LinkedList và ArrayList

* LinkedList không được dùng nhiều như ArrayList nhưng có một số trường hợp LinkedList là sự lựa chọn hợp lí hơn ArrayList. Chúng ta nên dùng LinkedList nếu:

* Ứng dụng không cần truy cập ngẫu nhiên trong mảng. Vì nếu cần chúng ta sẽ phải duyệt qua mảng để tìm kiếm phần tử phù hợp, độ phức tạp là O(n)
2)Ứng dụng thao tác thêm mới, xóa nhiều hơn truy cập dữ liệu. Khi đó thêm mới và xóa không phải thay đổi kích thước mảng nên nhanh hơn ArrayList.

 
</details>

##

<details>
	<summary> LIST, MAP ,LAMDA </summary>

##
### MAP

Map là một tập hợp các phần tử được sắp xếp theo thứ tự cụ thể, mà mỗi phần tử trong đó được hình thành bởi sự kết hợp của một cặp khóa và giá trị (key & value) với mỗi khóa là duy nhất trong map. 
```C++
int main(){
    map<int, ThongTin> SinhVien;
    SinhVien[101]={"Hoang",20};  //101 là key, hoàng 20 là value
    SinhVien[102]={"Tuan",18};
```

Trong map, các khóa (key) được sử dụng để sắp xếp và xác định giá trị (value) tương ứng được liên kết với nó. Mỗi khóa trong map là duy nhất và không được phép trùng lặp. Các giá trị trong map thì có thể trùng lặp, chúng có thể thay đổi giá trị, cũng như là được chèn hoặc xóa khỏi map.

```C++
 for(auto item:SinhVien){
        cout<<"ID= "item.first<<"",Ten:"<<item.second.ten"<<",Tuoi:"<<item.second.tuoi<<endl;
```
##
### LAMBDA

Lambda là function nhưng được viết ở cục bộ (viết ở hàm main) thay vì khai báo ở toàn cục. Lambda hay còn gọi là hàm nặc danh, nó có thể dùng để truyền vào 1 hàm khác và sử dụng 1 lần.
```C++
[ capture_clause ] ( parameter_list ) -> return_type {
    // lambda body
}
```
* capture_clause: Đây là phần mô tả cách biến từ phạm vi xung quanh sẽ được truyền vào lambda. Có hai kiểu capture:

[=]: Capture tất cả các biến từ phạm vi xung quanh theo giá trị (by value).

[&]: Capture tất cả các biến từ phạm vi xung quanh theo tham chiếu (by reference).

[x, y]: Chọn cụ thể các biến x và y để capture.

* parameter_list: Danh sách các tham số cho hàm lambda, tương tự như danh sách tham số cho một hàm thông thường.

* return_type: Kiểu dữ liệu của giá trị trả về của lambda (không bắt buộc). Lambda có thể trả về một giá trị bằng cách sử dụng return hoặc tự động suy luận kiểu dữ liệu nếu có lệnh return.

* lambda body: Phần này chứa mã nguồn của hàm lambda, thực hiện các công việc cụ thể.

```C++
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
```

</details>
</details>
	
</details>

##
<details>
<summary><h1>Embedded</h1></summary>	

 ##
 <details>
	<Summary>Giao Thức SPI,UART,I2C  </Summary>


## GIAO THỨC SPI

SPI (Serial Peripheral Interface) là một chuẩn truyền thông nối tiếp tốc độ cao do Motorola đề xuất.

• Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ.

• Giao tiếp song công, có thể truyền và nhận cùng một thời điểm.

• Khoảng cách truyền ngắn, được sử dụng để trao đổi dữ liệu với nhau giữa các chip trên cùng một bo mạch.

• Tốc độ truyền khoảng vài Mb/s.

• Các dòng vi điều khiển thường được tích hợp module giao tiếp SPI dùng để giao tiếp truyền dữ liệu với các vi điều khiển khác, hoặc giao tiếp với các ngoại vi bên ngoài như cảm biến, EEPROM, ADC, LCD, SD Card,…


Các thiết bị giao tiếp qua SPI có quan hệ master - slave. Master là thiết bị điều khiển (thường là vi điều khiển), còn slave (thường là cảm biến, màn hình hoặc chip nhớ) nhận lệnh từ master. Cấu hình đơn giản nhất của SPI là hệ thống một slave, một master duy nhất, nhưng một master có thể điều khiển nhiều hơn một slave.

<img src="https://arduinokit.vn/wp-content/uploads/2023/05/chuan-giao-tiep-spi-voi-nhieu-slaves-768x590.png">



Giao tiếp 1 Master với 1 Slave

Bus SPI gồm có 4 đường tín hiệu:
* SCLK: Serial Clock ( chân xung clock)
* MOSI: Master Out, Slave In ( truyền data đi cho slave)
* MISO: Master In, Slave Out (nhận data từ slave)
* SS: Slave Select( điều khiển để cho phép master điều khiển với slave nào)


#### Chân SS hoạt động như nào?

Thường Slave1,2,3 là những con sensor do nhà sản xuất đã nạp chương trình SPI. Có những case ngoại lệ. 

Nếu SS kéo xuống mức 0 (truyền bit 0) thì nó cho phép SS1 master giao tiếp với slave 1. Nếu SS mức 1 thì không đc giao tiếp với slave 1.

Nếu muốn master giao tiếp với slave 2, thì SS1 (master) kéo lên mức 1, SS2(slave) kéo xuống mức 0, SS3 (slave 3) kéo lên mức 1.

### Các bước truyền dữ liệu SPI

<img src="https://arduinokit.vn/wp-content/uploads/2023/05/nguyen-ly-hoat-dong-chuan-giao-tiep-spi.webp">

* Master ra tín hiệu xung nhịp.
 

* Master chuyển chân SS / CS sang trạng thái điện áp thấp, điều này sẽ kích hoạt slave.
 

* Master gửi dữ liệu từng bit một tới slave dọc theo đường MOSI. Slave đọc các bit khi nó nhận được.
 

* Nếu cần phản hồi, slave sẽ trả lại dữ liệu từng bit một cho master dọc theo đường MISO. Master đọc các bit khi nó nhận được.

### Các chế độ hoạt động:

CPOL dùng để chỉ trạng thái của chân SCK ở trạng thái nghỉ. Chân SCK giữ ở mức cao khi CPOL=1 hoặc mức thấp khi CPOL=0.

CPHA dùng để chỉ các mà dữ liệu được lấy mẫu theo xung. Dữ liệu sẽ được lấy ở cạnh lên của SCK khi CPHA = 0 hoặc cạnh xuống khi CPHA = 1.

- CPHA = 1: đầu tiên cho 1 xung clock trước, sau đó đưa dữ liệu vào, xung clock tiếp theo sẽ đẩy dữ liệu đi.

- CPHA = 0: đưa data vào trước, sau đó dùng xung clock để đẩy data đi.
- <img src="https://user-images.githubusercontent.com/133474779/257699085-5e3edd15-bbdc-40c8-8d42-8bb46b62b65e.png">

### Ưu và nhược điểm của giao thức SPI

### Ưu điểm

- Tốc độ truyền thông cao: SPI cho phép truyền dữ liệu với tốc độ rất nhanh, thường đạt được tốc độ Mbps hoặc thậm chí hàng chục Mbps. Điều này rất hữu ích khi cần truyền dữ liệu nhanh và đáng tin cậy trong các ứng dụng như truyền thông không dây, điều khiển từ xa và truyền dữ liệu đa phương tiện.

- Giao tiếp đồng bộ: SPI sử dụng tín hiệu xung đồng hồ (SCLK) để đồng bộ hoá việc truyền dữ liệu giữa master và slave. Điều này đảm bảo tính tin cậy của dữ liệu truyền, và master có thể điều khiển quá trình truyền thông theo ý muốn.

- Khả năng truyền thông hai chiều: SPI cho phép truyền dữ liệu theo hai chiều, từ master tới slave và từ slave về master. Điều này rất hữu ích trong các ứng dụng yêu cầu truyền thông hai chiều như truyền thông với các cảm biến hoặc thiết bị ngoại vi.

- Hỗ trợ nhiều thiết bị slave: SPI cho phép kết nối nhiều thiết bị slave với một master duy nhất. Master có thể chọn từng slave để truyền dữ liệu, giúp mở rộng khả năng kết nối và giao tiếp với nhiều thiết bị.

### Nhược điểm

- Số lượng chân kết nối: SPI yêu cầu nhiều chân kết nối hơn so với các giao thức truyền thông khác như I2C. Điều này có thể tạo ra sự rắc rối và giới hạn trong việc thiết kế mạch và kết nối với các thành phần.

- Độ dài cáp giới hạn: Tín hiệu SPI có độ tương phản cao và tốc độ truyền thông nhanh, do đó, độ dài cáp kết nối giữa các thiết bị cần được giới hạn để tránh sự mất mát dữ liệu và nhiễu.

- Không hỗ trợ chia sẻ đường truyền: SPI không cung cấp cơ chế chia sẻ đường truyền giữa các thiết bị slave. Điều này có nghĩa là chỉ một slave được truyền dữ liệu tại một thời điểm. Điều này có thể tạo ra hạn chế trong việc giao tiếp.

## UART

<img src="https://user-images.githubusercontent.com/133474779/257703514-b43f2639-f3c1-48ec-a909-dad3fc10eeed.png">

UART là giao thức không đồng bộ, do đó không có đường clock nào điều chỉnh tốc độ truyền dữ liệu. Người dùng phải đặt cả hai thiết bị để giao tiếp ở cùng tốc độ. Tốc độ này được gọi là tốc độ truyền, được biểu thị bằng bit trên giây hoặc bps.

Các UART giao tiếp giữa hai nút riêng biệt bằng cách sử dụng một cặp dẫn và một nối đất chung.

- TX: truyền dữ liệu
  
- RX: nhận dữ liệu

Tại 1 thời điểm, UART có thể cùng truyền và nhận dữ liệu

Ở trạng thái không giao tiếp, chân TX luôn ở mức cao (có điện trở kéo lên).

UART là một giao thức một master, một slave, trong đó một thiết bị được thiết lập để giao tiếp với duy nhất một thiết bị khác.

*Khi UART nhận phát hiện một bit start, nó bắt đầu đọc các bit đến ở một tần số cụ thể được gọi là tốc độ truyền (baud rate). Tốc độ truyền là thước đo tốc độ truyền dữ liệu, được biểu thị bằng bit trên giây (bps – bit per second), có nhiều tốc độ truyền khã nhau từ 9600 bps -> 115200 bps. Cả hai UART đều phải hoạt động ở cùng một tốc độ truyền. Tốc độ truyền giữa UART truyền và nhận chỉ có thể chênh lệch khoảng 10% trước khi thời gian của các bit bị lệch quá xa.*


<img src="https://tapit.vn/wp-content/uploads/2018/06/1-2.png">

<img src="https://developer.electricimp.com/sites/default/files/attachments/images/uart/uart3.png">


**Start bit**: Để bắt đầu truyền dữ liệu, UART truyền sẽ kéo đường truyền từ mức cao xuống mức thấp trong một chu kỳ clock. Khi UART nhận phát hiện sự chuyển đổi điện áp cao xuống thấp, nó bắt đầu đọc các bit trong khung dữ liệu ở tần số của tốc độ truyền.

Khung dữ liệu chứa dữ liệu thực tế được chuyển. Nó có thể dài từ 5 bit đến 8 bit nếu sử dụng bit chẵn lẻ. Nếu không sử dụng bit chẵn lẻ, khung dữ liệu có thể dài 9 bit. Trong hầu hết các trường hợp, dữ liệu được gửi với bit ít quan trọng nhất trước tiên.

**Bit chẵn lẻ**: là một cách để UART nhận cho biết liệu có bất kỳ dữ liệu nào đã thay đổi trong quá trình truyền hay không (bức xạ điện từ, tốc độ truyền không khớp hoặc truyền dữ liệu khoảng cách xa). Sau khi UART nhận đọc khung dữ liệu, nó sẽ đếm số bit có giá trị là 1 và kiểm tra xem tổng số là số chẵn hay lẻ. Nếu bit chẵn lẻ là 0 (tính chẵn), thì tổng các bit 1 trong khung dữ liệu phải là một số chẵn. Nếu bit chẵn lẻ là 1 (tính lẻ), các bit 1 trong khung dữ liệu sẽ tổng thành một số lẻ. Khi bit chẵn lẻ khớp với dữ liệu, UART sẽ biết rằng quá trình truyền không có lỗi. Nhưng nếu bit chẵn lẻ là 0 và tổng là số lẻ; hoặc bit chẵn lẻ là 1 và tổng số là chẵn, UART sẽ biết rằng các bit trong khung dữ liệu đã thay đổi.

**Bit dừng**: để báo hiệu sự kết thúc của gói dữ liệu, UART gửi sẽ điều khiển đường truyền dữ liệu từ điện áp thấp đến điện áp cao trong ít nhất khoảng 2 bit.

### CheckSUM

Ví dụ truyền 4byte OxC5 + OxA3+OxA2+ OxD4 = Ox2DE 

Thay vì truyền 4 byte thì MCUA sẽ truyền 5byte và MCUB nhận 5 byte , sau đó lấy 4 byte đầu tiên cộng lại với nhau rồi `and` với 0xFF rồi so sánh với byte thứ 5, nếu bằng thì nó bảo toàn, còn sai thì nó sai số. Các chuẩn giao tiếp đều có checksum.

##

## I2C

I2C kết hợp các tính năng tốt nhất của SPI và UART. Với I2C, bạn có thể kết nối nhiều slave với một master duy nhất (như SPI) và bạn có thể có nhiều master điều khiển một hoặc nhiều slave. Điều này thực sự hữu ích khi bạn muốn có nhiều hơn một vi điều khiển ghi dữ liệu vào một thẻ nhớ duy nhất hoặc hiển thị văn bản trên một màn hình LCD.

I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
 

* SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu.
 

* SCL (Serial Clock) - đường mang tín hiệu xung nhịp.
 

I2C là một giao thức truyền thông nối tiếp, vì vậy dữ liệu được truyền từng bit dọc theo một đường duy nhất (đường SDA).


*Giống như SPI, I2C là đồng bộ, do đó đầu ra của các bit được đồng bộ hóa với việc lấy mẫu các bit bởi một tín hiệu xung nhịp được chia sẻ giữa master và slave. Tín hiệu xung nhịp luôn được điều khiển bởi master.*

### Cách hoạt động của I2C

<img src="https://dientutuonglai.com/uploads/media/vi-dieu-khien/tin-nhan-i2c.png?1615623356957">

* Master gửi điều kiện khởi động đến mọi slave được kết nối bằng cách chuyển đường SDA từ mức điện áp cao sang mức điện áp thấp trước khi chuyển đường SCL từ mức cao xuống mức thấp.

* Master gửi cho mỗi slave địa chỉ 7 hoặc 10 bit của slave mà nó muốn giao tiếp, cùng với bit đọc / ghi.

* Bit đọc/ghi cho slave biết master muốn ghi dữ liệu vào nó hay nhận dữ liệu từ nó. Nếu master muốn gửi dữ liệu đến slave, bit đọc / ghi ở mức điện áp thấp. Nếu master đang yêu cầu dữ liệu từ slave, thì bit ở mức điện áp cao.
Mỗi slave sẽ so sánh địa chỉ được gửi từ master với địa chỉ của chính nó. Nếu địa chỉ phù hợp, nó sẽ gửi lại một bit ACK điện áp thấp cho master. Nếu địa chỉ không khớp, slave không làm gì cả và đường SDA vẫn ở mức cao

* Master gửi hoặc nhận khung dữ liệu.

* Sau khi mỗi khung dữ liệu được chuyển, thiết bị nhận trả về một bit ACK khác cho thiết bị gửi để xác nhận đã nhận thành công khung.

* Để dừng truyền dữ liệu, master gửi điều kiện dừng đến slave bằng cách chuyển đổi mức cao SCL trước khi chuyển mức cao SDA.

 [Chi tiết ](https://dientutuonglai.com/chuan-giao-tiep-i2c-la-gi.html)

 ### SO SÁNH SPI UART I2C 

 <img src ="https://scontent.fsgn5-15.fna.fbcdn.net/v/t1.6435-9/144962711_249915713337702_340587713684986630_n.png?_nc_cat=108&ccb=1-7&_nc_sid=730e14&_nc_ohc=HgA9E9WGASgAX-DdE3l&_nc_ht=scontent.fsgn5-15.fna&oh=00_AfDCesQaEIHuysN6gZ3bEKW1Tytr2PYFgzmvrt8myfOcyw&oe=65337A97">

 Giao thức I2C, SPI và UART là các giao thức truyền thông thông dụng trong việc kết nối các thiết bị điện tử với nhau. Dưới đây là sự khác nhau giữa chúng:
 
1. Giao thức I2C (Inter-Integrated Circuit):

- I2C là giao thức truyền thông hai dây, bao gồm một dây dữ liệu (SDA) và một dây xung đồng hồ (SCL).
  
- I2C được sử dụng để kết nối nhiều thiết bị với nhau thông qua cùng một bus giao tiếp.
  
- Giao thức I2C sử dụng địa chỉ để truyền dữ liệu giữa các thiết bị, giúp phân biệt được địa chỉ của từng thiết bị.
  
2. Giao thức SPI (Serial Peripheral Interface):
   
- SPI là giao thức truyền thông đồng bộ, dựa trên việc truyền dữ liệu đồng thời trên các dây MOSI (Master-Out Slave-In) và MISO (Master-In Slave-Out), cùng với dây xung đồng hồ (SCLK) và dây chọn (SS).
  
- Giao thức SPI thường sử dụng chế độ master-slave, trong đó một thiết bị được gọi là master điều khiển quá trình truyền thông, trong khi các thiết bị khác được gọi là slave.
  
3. Giao thức UART (Universal Asynchronous Receiver-Transmitter):
   
- UART là giao thức truyền thông không đồng bộ, dựa trên việc truyền dữ liệu qua hai dây TX (Transmit) và RX (Receive).
  
- Giao thức UART thực hiện việc chuyển đổi dữ liệu từ dạng thông điệp thành dạng dòng liên tiếp và ngược lại.
  
- UART thường được sử dụng để kết nối máy tính với các cổng nối tiếp truyền thống (RS-232) hoặc các thiết bị nhúng như vi điều khiển.

</details>

##

<details>
	<summary>TIMER</summary>

##

Bộ đếm/Bộ định thời: Đây là các ngoại vi được thiết kế để thực hiện một nhiệm vụ đơn giản: đếm các xung nhịp. Mỗi khi có thêm một xung nhịp tại đầu vào đếm thì giá trị của bộ đếm sẽ được tăng lên 01 đơn vị (trong chế độ đếm tiến/đếm lên) hay giảm đi 01 đơn vị (trong chế độ đếm lùi/đếm xuống).
```C++
  / Time base configuration /
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 16); //bộ chia, giới hạn bộ đếm

  / Clear TIM4 update flag /
  TIM4_ClearFlag(TIM4_FLAG_UPDATE); //khi đếm đến giới hạn bộ đếm thì sẽ có cờ tràn(khi tràn -> xảy ra ngắt). Xóa cờ này đi để chắc chắn không tràn

  / Enable update interrupt /
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE); //đăng kí ngắt vào bảng vector ngắt, bảng vector ngắt chứa nhiều địa chỉ 
  
  / enable interrupts /
  enableInterrupts(); //bật các ngắt trong bảng vector

  / Enable TIM4 /
  TIM4_Cmd(ENABLE); //timer sẽ bắt đầu đếm

```
Prescaler : bộ chia trước ( tối đa 16 bit)

**Counter setting**

Prescaler : fAPB2 là 8MHz. Khi tầng số này đưa vào khối TIMER thì sẽ qua bộ chia trước. Sau khi chia thì ra được tần số hoạt động của TIMER đó.

Counter mode: Up ( đếm lên)

STM32F103 có 2 nguồn cấp dao động chính:

* HSE(High Speed External) : bộ dao động ngoại tốc độcao(4-16MHz), cấp cho CPU hoạt động.
* HIS(High Speed Internal): bộ dao động nội tốc độ 8Mhz, cấp cho CPU trong TH ko có HSE.

### Nguyên lí hoạt động

  Timer là một bộ đếm độc lập với CPU. Cứ sau mỗi khoảng thời gian t( do người dùng cài đặt) thì giá trị của thanh counter CNT sẽ tăng lên 1 đơn vị. Khi giá trị này bằng với giá trị thanh ghi tự động nạp lại ARR thì bộ đếm sẽ trở về 0 và đông thời sinh ra một ngắt cập nhật.

  

### Lựa chọn Clock cho TIMER

Counter clock là nguồn gốc của hoạt động tăng/ giảm giá trị CNT, clock này có thể được cấu hình lựa chọn từ các nguồn sau:

– Internal clock (CK_INT): Chọn nguồn clock từ clock của hệ thống, có thể là từ thạch anh dao động tần số cao bên ngoài (HSE) hay bộ giao động RC tần số cao được tích hợp sẵn bên trong STM(HSI), từ đấy qua các bộ chia tần của hệ thống clock để cấp cho ngoại vi timer (TIM2 đến TIM5 có clock CK_PSC đầu vào bằng clock của bus APB1, TIM9 đến TIM11 có clock Ck_PSC bằng clock bus APB2). CK_PSC là clock chưa qua bộ Prescaler của khối timer.

<img scr="https://tapit.vn/wp-content/uploads/2019/07/timer_stm32f411_clockselection_tapit.png">

– External clock mode1: Nếu chọn mode này thì counter có thể đếm mỗi khi chân external input pin (TIx) xuất hiện sườn lên hoặc sườn xuống, người dùng cấu hình chọn sườn.

– External clock mode2: Nếu chọn mode này thì counter có thể đếm mỗi khi chân external trigger input (ETR) xuất hiện sườn lên hoặc sườn xuống. (Mode này chỉ có ở các bộ TIM2, TIM3, TIM4).

– Internal trigger inputs (ITRx): Mode này cho phép sử dụng một timer làm bộ prescaler cho một bộ timer khác.



### TIMER 0

*  0 là 1 bộ timer/ counter 8 bit
* Có bộ chia trước, dùng chung với watchdog timer
* Có thể lựa chọn nguồn xung clock nội hay ngoại (nối với chân T0CKI) tùy theo cách cấu hình
* Có phát hiện ngắt khi tràn bộ đếm từ 0xFF về 0x00
* Cho phép chọn cạnh của xung đếm
* Không có bit cho phép chạy hay ngừng ( free run timer)

<img src="https://deviot.vn/storage/deviot/timer0_block.png">

Để cấu hình cho timer 0 thì ta cần phải tác động lên thanh ghi OPTION_REG:

<img src="https://deviot.vn/storage/deviot/option_reg.png">

Chức năng của các bit:

Bit 7: bit điều khiển điện trở treo port B (RBPU) 

Bit 6: bit chọn cạnh ngắt (INTEDG)

Bit 5: bit chọn nguồn xung cho timer 0 ( T0CS)

T0CS = 1: nguồn xung ngoại lấy từ chân T0CKI

T0CS = 0: nguồn xung clock nội (Fosc/4)

Bit 4: Bit chọn cạnh ngắt tích cực (T0SE)

Bit 3: bit gán bộ chia trước (PSA)

PSA = 1: gán cho watchdog timer (WDT)

PSA = 0: gán cho timer 0

Bit 2-0 : các bit chọn tỷ lệ bộ chia trước PS<2:0>

[Link tham khảo](https://deviot.vn/tutorials/pic.22296474/timer-0-va-ung-dung-ngat.54491851)




</details>

##

<details>
	<summary>NGẮT</summary>

 1. Khái niệm

* Ngắt là đoạn chương trình độc chạy độc lập với chương trình chính, có độ ưu tiên cao, khi xảy ra ngắt nó sẽ chạy hết chương trình ngắt sau đó mới tiếp tục chạy chương trình chính.

* Ngắt là một số sự kiện khẩn cấp bên trong hoặc bên ngoài bộ vi điều khiển xảy ra, buộc vi điều khiển tạm dừng thực hiện chương trình hiện tại, phục vụ ngay lập tức nhiệm vụ mà ngắt yêu cầu – nhiệm vụ này gọi là trình phục vụ ngắt.

* Khi xảy ra ngắt, con trỏ PC sẽ trỏ đến địa chỉ ngắt.

* Mỗi vi điều khiển có 1 trình phục vụ ngắt riêng (độ ưu tiên ngắt, địa chỉ phục vụ ngắt, cờ ngắt)

### Trình phục vụ ngắt

Đối với mỗi ngắt thì phải có một trình phục vụ ngắt (ISR) hay trình quản lý ngắt để đưa ra nhiệm vụ cho bộ vi điều khiển khi được gọi ngắt. Khi một ngắt được gọi thì bộ vi điều khiển sẽ chạy trình phục vụ ngắt. Đối với mỗi ngắt thì có một vị trí cố định trong bộ nhớ để giữ địa chỉ ISR của nó. Nhóm vị trí bộ nhớ được dành riêng để lưu giữ địa chỉ của các ISR được gọi là bảng vector ngắt.

<img src="https://3.bp.blogspot.com/-csPsEHR4cDQ/UAhdR3qKMUI/AAAAAAAABas/qb982xtnIkc/s1600/hinh1.jpg">


### Các loại Ngắt 

Một số ngắt phổ biến trên vi điều khiển phổ biến mà chúng ta thường sử dụng: 

– Ngắt ngoài: Sự kiện là khi sự thay đổi sườn tín hiệu (edge) sườn lên, sườn xuống, hoặc cả 2. 

– Ngắt UART: Thường sử dụng ngắt nhận, sự kiện là khi buffer nhận đủ 1 byte dữ liệu

 Ngắt truyên thông:

  ![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/2b4f4abd-10de-4d1c-9546-ac5563160e6f)

:arrow_right: UART A và UART B có 2 thời điểm truyền, nhận khác nhau. Do khi truyền nhận data có thể bị thiếu hoặc sai.

:arrow_right: Do đó người ta sử dụng ngắt truyền thông ở UART B: khi chân RX có data thì nó sẽ vào chương trình ngắt để đọc data, đọc xong thì quay lại chương trình chính.


– Ngắt ADC: Thường sử dụng khi hoàn thành việc chuyển đổi ADC


– Ngắt Timer: Thường sử dụng khi tràn thanh ghi đếm, khi cờ tràn =1 thì sẽ dừng chương trình chính lại và trỏ con trỏ PC đến timer chạy ngắt timer. Muốn thoát chương trình thì phải có reset thanh ghi timer , reset cờ tràn. 

### Qúa trình Ngắt trong VDK

khi xảy ra Interrupt, vi điều khiển sẽ thực hiện qua các bước sau: 

1. Thực hiện xong câu lệnh đang thực hiện (câu lệnh ở mã máy sau quá trình compiler, asembler từ ngôn ngữ bật cao do người dùng viết. Để thực hiện 1 câu lệnh ở mã máy, vi điều khiển thường thực hiện các bước sau: lấy lệnh từ bộ nhớ; giải mã lệnh; thực thi lệnh). 

2. Lưu ngữ cảnh gồm lưu địa chỉ câu lệnh tiếp theo sẽ thực hiện (giá trị thanh ghi Program Counter), lưu trạng thái năng lượng đang hoạt động (trong thanh ghi Status) vào vùng nhớ Stack, gọi là quá trình Stacking.(Vùng nhớ Stack là vùng nhớ First In Last Out.)

3. Xóa bit cho phép ngắt toàn cục trong thanh ghi Status, đưa vi điều khiển về chế độ hoạt động bình thường (active mode) nếu nó đang ở chế độ tiết kiệm năng lượng. Bit cho phép ngắt cũng có thể được bật lên lại để cho phép ngắt chồng ngắt (Nested Interrupt)

4. Vi điều khiển thực thi chương trình phục vụ ngắt (ISR) bằng cách nạp địa chỉ câu lệnh đầu tiên của chương trình phục vụ ngắt vào thanh ghi PC. (Địa chỉ này cũng là địa chỉ của vecter ngắt trong interrupt vector table)

5. Khi thực hiện xong chương trình phục vụ ngắt, vi điều khiển sẽ thực hiện quá trình unstacking: nạp lại giá trị thanh ghi PC đã lưu, bật lại bit cho phép ngắt toàn cục, quay về trạng thái năng lượng ban đầu.
  
</details>


<details>
  <summary><h2>CAN</h2></summary>
	
**1. Khái niệm:**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/263dd880-f0be-44ab-ba28-f9d581501a57)

- Giao thức CAN có nhiều node, 1 node gồm:
  	- CAN Controller: truyền và nhận dữ liệu qua 2 dây Tx, Rx.
  	- CAN Tranceiver: xuất ra 2 mức điện áp CAN_H và CAN_L.
- 2 đầu dây có 2 điện trở 120Ω -> tiêu chuẩn CAN 2.0
- 1 node có thể vừa truyền và nhận data.
- CAN -> chống nhiễu (bắt chéo 2 dây CAN_H, CAN_L -> khoảng cách tiếp xúc 2 dây với nguồn phát ra từ trường là như nhau -> độ nhiễu như nhau)
- MCU sẽ gửi tín hiệu (bit 1, 0) xuống CAN Controller -> điều khiển CAN Tranceiver xuất 2 điện áp CAN_H, CAN_L

**2. Trạng thái "dominant" và "recessive":**

- Có 2 dạng truyền: CAN low speed, CAN high speed
  
| Thông số | CAN low speed | CAN high speed |
|---|:---:|:---:|
|Tốc độ|125 kb/s|125 kb/s tới 1 Mb/s|
|Số nút trên bus|2 tới 20|2 tới 30|
|Trạng thái dominant|CAN_H = 4V; CAN_L = 1V|CAN_H = 3.25V; CAN_L = 1.5V|
|Trạng thái recessive|CAN_H = 1.75V; CAN_L = 3.25V|CAN_H = 2.5V; CAN_L = 2.5V|
|Tính chất của cap|30pF giữa cáp và dây|2*120 ohm|
|Mức điện áp cung cấp|5V|5V|

- Giả sử CAN tuân theo dạng truyền CAN low speed -> CAN controller sẽ nhận giá trị |CAN_H - CAN_L|
  	- Nếu >= 3V -> CAN ở trạng thái dominant (bit 0)
  	- Nếu <= 1.5V -> CAN ở trạng thái recessive (bit 1)
- Tại 1 thời điểm, chỉ có 1 node truyền, các node còn lại nhận. Để nhận biết node truyền, node nhận thì ta dựa vào bit ID, bit ID càng nhỏ độ ưu tiên càng cao.
- Giả sử 1 node xuất ra CAN_H = 4V, CAN_L = 1V thì nó cũng có thể nhận lại mức điện áp đó. Tại thời điểm đó, nó hiểu là chỉ có 1 mình nó truyền dữ liệu.
  
***Ví dụ:*** Có 3 MCU truyền CAN low speed
MCU A: 0000 0010
MCU B: 0000 1000
MCU C: 0001 0000

:arrow_right: Giả sử MCU A truyền bit 0, MCU B và C truyền bit 1 thì khi nhận lại các MCU A, B, C không nhận lại các mức điện áp CAN_H, CAN_L ban đầu. Khi đó, MCU A hiểu là ngoài nó còn có các MCU khác cũng đang truyền dữ liệu. Mà MCU A có địa chỉ nhỏ hơn MCU B, C nên lúc đó MCU A sẽ vào chế độ truyền, MCU B và C sẽ vào chế độ nhận.

- Trong khoảng delay, CAN_H và CAN_L đều bằng 0 -> CAN controller nhận về giá trị hiệu bằng 0 -> dấu hiệu để chuyển sang bit tiếp theo.

**3. Data frame:**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/069d6ba6-89f4-4767-9d80-119be72854af)

Data Frame CAN (Phiên bản 2.0A) tiêu chuẩn bao gồm bảy trường bit khác nhau:

**3.1. Trường bắt đầu khung (Start Of Frame Field – SOF)**

- Với cả 2 định dạng của chuẩn CAN 2.0 thì trường bắt đầu là vị trí của bit đầu tiên trong khung. Trường này chiếm 1 bit dữ liệu. Bit đầu tiên này là một Dominant Bit (mức logic 0) đánh dấu sự bắt đầu của một Data Frame.

**3.2. Trường xác định quyền ưu tiên (Arbitration Field)**

- Định dạng vùng xác định quyền ưu tiên là khác nhau đối với dạng khung chuẩn và khung mở rộng.
  
	- Định dạng chuẩn: vùng xác định quyền ưu tiên có độ dài 12 bit, bao gồm 11 bit ID và 1 bit RTR.

	- Định dạng mở rộng: trường xác định quyền ưu tiên có độ dài 32 bit, bao gồm có 29 bit ID, 1 bit SRR, 1 bit IDE và 1 bit RTR

- Trong đó:
	- Bit RTR (Remote Transmission Request)
		- Là bit dùng để phân biệt khung là Data Frame hay Remote Frame.
		- Nếu là Data Frame, bit này luôn bằng 0 (Dominant Bit).
		- Nếu là Remote Frame, bit này luôn bằng 1 (Recessive Bit).
	  	- Vị trí bit này luôn nằm sau bit ID.
	- Trường hợp nếu Data Frame và Remote Frame có cùng ID được gửi đi đồng thời thì Data Frame sẽ được ưu tiên hơn.
   
	- Bit SRR (Substitute Remote Request)
		- Bit này chỉ có ở khung mở rộng.
		- Bit này có giá trị là 1 (Recessive Bit).
		- So với vị trí tương ứng trong khung chuẩn thì bit này trùng với vị trí của bit RTR nên còn được gọi là bit thay thế (Substitute).
	- Giả sử có hai Node cùng truyền, một Node truyền Data Frame chuẩn, một Node truyền Data Frame mở rộng có ID giống nhau thì Node truyền khung chuẩn sẽ thắng phân xử quyền ưu tiên vì đến vị trí sau ID, khung chuẩn là bit RTR = 0, còn khung mở rộng là bit SRR = 1. Như vậy, khung chuẩn chiếm ưu thế hơn so với khung mở rộng khi có ID như nhau.
	- Bit IDE (Identifier Extension)
		- Đây là bit phân biệt giữa loại khung chuẩn và khung mở rộng: IDE = 0 quy định khung chuẩn, IDE = 1 quy định khung mở rộng.
		- Bit này nằm ở trường xác định quyền ưu tiên với khung mở rộng và ở trường điều khiển với khung chuẩn.
    
**3.3. Trường điều khiển (Control Field)**
- Khung chuẩn và khung mở rộng có định dạng khác nhau ở trường này:
	- Khung chuẩn gồm IDE, r0 và DLC (Data Length Code).
	- Khung mở rộng gồm r1, r0 và DLC.
- Trong đó:
	- Bit IDE
		- Dùng phân biệt loại khung (đã được trình bày ở trên).
		- Bit r0, r1 (hai bit dự trữ)
	- Tuy hai bit này phải được truyền là Recessive Bit bởi bộ truyền nhưng bộ nhận không quan tâm đến giá trị 2 bit này. Bộ nhận có thể nhận được các tổ hợp 00, 01, 10 hoặc 11 của r1 và r0 nhưng không coi đó là lỗi mà bỏ qua và nhận thông điệp bình thường.
	- DLC (Data Length Code)
		- Có độ dài 4 bit quy định số byte của trường dữ liệu của Data Frame
		- Chỉ được mang giá trị từ 0 đến 8 tương ứng với trường dữ liệu có từ 0 đến 8 byte dữ liệu. Data Frame có thể không có byte dữ liệu nào khi DLC = 0.
		- Giá trị lớn hơn 8 không được phép sử dụng. Hình dưới mô tả các loại mã bit mà DLC có thể chứa để quy định số byte của trường dữ liệu.
    
**3.4. Trường dữ liệu (Data Field)**

- Trường này có độ dài từ 0 đến 8 byte tùy vào giá trị của DLC ở trường điều khiển.
  
**3.5. Trường kiểm tra (Cyclic Redundancy Check Field – CRC)**

- Trường kiểm tra hay trường CRC gồm 16 bit và được chia làm hai phần là:
	- CRC Sequence: gồm 15 bit CRC tuần tự
	- CRC Delimiter: là một Recessive Bit làm nhiệm vụ phân cách trường CRC với trường ACK
	- Mã kiểm tra CRC phù hợp nhất cho các khung mà chuỗi bit được kiểm tra có chiều dài dưới 127 bit, mã này thích hợp cho việc phát hiện các trường hợp sai nhóm (Bus Error). Ở đây, tổng bit từ trường bắt đầu (SOF) đến trường dữ liệu (Data Field) tối đa là 83 bit (khung định dạng chuẩn) và 103 bit (khung định dạng mở rộng).=> Trường CRC bảo vệ thông tin trong Data Frame và Remote Frame bằng cách thêm các bit kiểm tra dự phòng ở đầu khung truyền. Ở đầu khung nhận, cũng sẽ tính toán CRC như bộ truyền khi đã nhận dữ liệu và so sánh kết quả đó với CRC Sequence mà nó đã nhận được, nếu khác nhau tức là đã có lỗi, nếu giống nhau tức là đã nhận đúng từ trường SOF đến trường dữ liệu.
   
**3.6. Trường báo nhận (Acknowledge Field – ACK)**

- Trường báo nhận hay trường ACK có độ dài 2 bit và bao gồm hai phần là ACK Slot và ACK Delimiter.
	- ACK Slot: có độ dài 1 bit, một Node truyền dữ liệu sẽ thiết lập bit này là Recessive. Khi một hoặc nhiều Node nhận chính xác giá trị thông điệp (không có lỗi và đã so sánh CRC Sequence trùng khớp) thì nó sẽ báo lại cho bộ truyền bằng cách truyền ra một Dominant Bit ngay vị trí ACK Slot để ghi đè lên Recessive Bit của bộ truyền.
	- ACK Delimiter: có độ dài 1 bit, nó luôn là một Recessive Bit. Như vậy, ta thấy rằng ACK Slot luôn được đặt giữa hai Recessive Bit là CRC Delimiter và ACK Delimiter.
   
**3.7. Trường kết thúc (End Of Frame Field – EOF)**

- Trường EOF là trường thông báo kết thúc một Data Frame hay Remote Frame.
- Trường này gồm 7 Recessive Bit.
</details>



