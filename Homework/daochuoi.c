#include <stdio.h>

void reverse_words_order(char *str) {
    int length = 0;
    int word_start = 0;
    int word_end = 0;

    while (str[length] != '\0') {
        length++;
    }

    while (word_end <= length) {
        if (str[word_end] == ' ' || str[word_end] == '\0') {
            // Đảo ngược từ từ word_start đến word_end - 1
            int start = word_start;
            int end = word_end - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            word_start = word_end + 1;  // Bắt đầu từ ký tự sau khoảng trắng hoặc ký tự kết thúc từ
        }
        word_end++;
    }

    // Đảo ngược toàn bộ chuỗi
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char input_str[100];
    printf("Nhập chuỗi: ");
    fgets(input_str, sizeof(input_str), stdin);

    reverse_words_order(input_str);
    printf("Kết quả: %s\n", input_str);

    return 0;
}