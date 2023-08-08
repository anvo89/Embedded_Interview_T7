#include <stdio.h>

char *number[] = {"không", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};
char *unit[] = {"", "mươi", "trăm", "nghìn", "triệu", "tỷ"};

void print_hundreds(int digit) {
    printf("%s ", number[digit]);
    printf("%s ", unit[2]);
}

void print_tens(int digit) {
    if (digit > 0) {
        printf("%s ", number[digit]);
        printf("%s ", unit[1]);
    } else {
        printf("linh ");
    }
}

void convert_to_word(int num) {
    if (num >= 10000000000) {
        printf("Số quá lớn\n");
        return;
    }

    // Tách thành các chữ số riêng biệt lưu trong mảng digits
    int digits[12];
    int num_digits = 0;

    if (num == 0) {
        digits[num_digits++] = 0;
    }

    while (num > 0) {
        digits[num_digits] = num % 10;
        num /= 10;
        num_digits++;
    }

    int continuous_zeros = 0; // Số lượng số 0 liên tục

    // In cách đọc số theo yêu cầu
    for (int j = num_digits - 1; j >= 0; j--) {
        if (digits[j] == 0) {
            continuous_zeros++;
        } else {
            if (continuous_zeros > 0) {
                // Xử lý trường hợp số 0 liên tục
                for (int k = 0; k < continuous_zeros; k++) {
                    if (k == continuous_zeros - 1 && (j == 3 || j == 6 || j == 9)&&digits[3]!=0) {
                        printf("%s ", unit[(j / 3) + 1]);
                    }
                
        
                else if(continuous_zeros>0 &&digits[0]!=0){
                    if (digits[2]==0||digits[5]==0||digits[8]){
                        printf("không trăm ");
                    }
                }
                 if(continuous_zeros>0 &&digits[0]!=0){
                    if (digits[1]==0){
                        printf("linh ");
                    }
                continuous_zeros = 0;
            }}
            }
            if (j == 4 && digits[3] == 0&& digits[4]!=1) {
                printf("%s ", number[digits[j]]);
                printf("mươi nghìn ");
            } 
                else if (digits[4]==1 &&digits[3]==0){
                printf("mười nghìn ");
        }

            else if ((j == 1 || j == 4 || j == 7 || j == 10)) {
                if (j == 1 && digits[1] == 1||j==4&&digits[4]==1) {
                    printf("mười ");
                } else {
                    print_tens(digits[j]);
                }
            }
            
            else if ((j == 2 || j == 5 || j == 8 || j == 11)) {
                if (j==2&&digits[2]==0){
                    printf("không trăm");
                }
                else{
                print_hundreds(digits[j]);
            }}
            else if (j == 3 && digits[3] > 0) {
                printf("%s ", number[digits[j]]);
                printf("%s ", unit[3]);
            }
            else if (j == 3 && digits[3] == 0) {
                printf("%s ", unit[0]);
            }
            else if (j == 6) {
                printf("%s ", number[digits[j]]);
                printf("%s ", unit[4]);
            }
            else if (j == 9) {
                printf("%s ", number[digits[j]]);
                printf("%s ", unit[5]);
            }
            else if (digits[0] == 5) {
                printf("lăm");
            }
            else {
                printf("%s ", number[digits[j]]);
            }
        }
    }
}

int main() {
    int num;
    printf("Nhập một số: ");
    scanf("%d", &num);

    convert_to_word(num);

    return 0;
}
