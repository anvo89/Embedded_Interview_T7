#include <stdio.h>

char *number[] = {"", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};
char *unit[] = {"", "mươi", "trăm", "nghìn", "triệu", "tỷ"};

void print_hundreds(int digit) {
    if (digit != 0) {
        printf("%s ", number[digit]);
        printf("%s ", unit[2]);
    }
}

void print_tens(int digit) {
    if (digit == 0) {
        printf("linh ");
    } else {
        printf("%s ", number[digit]);
        printf("%s ", unit[1]);
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

    // In cách đọc số theo yêu cầu
    int unitIndex = (num_digits - 1) / 3;
    for (int j = num_digits - 1; j >= 0; j--) {
        int position = num_digits - j - 1;

        if ((position == 1 || position == 4 || position == 7) && digits[j] != 0) {
            if (digits[j] == 1) {
                printf("mười ");
            } else {
                print_tens(digits[j]);
            }
            printf("%s ", unit[position / 3]);
        } else if ((position == 2 || position == 5 || position == 8) && digits[j] != 0) {
            printf("%s ", number[digits[j]]);
            printf("%s ", unit[position / 3]);
        } else if ((position == 0 || position == 3 || position == 6 || position == 9) && digits[j] != 0) {
            print_hundreds(digits[j]);
            if (position == 3) {
                printf("%s ", unit[3]);
            } else if (position == 6) {
                printf("%s ", unit[4]);
            } else if (position == 9) {
                printf("%s ", unit[5]);
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
