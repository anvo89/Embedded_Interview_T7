#include<stdio.h>
#include<string.h>
#define MAX_WORDS 100

bool isEqual(const char arr1[], const char arr2[]) {
    while (*arr1 == *arr2) {
        if (*arr1 == '\0' && *arr2 == '\0') {
            return true;
        }
        arr1++;
        arr2++;
    }
    return false;
}

typedef struct {
    char *word;
    int count;
} WordCount;
void countAndPrintOccurrences(const char *str) {
    WordCount wordCounts[MAX_WORDS] = {0}; // Mảng tĩnh để lưu trữ từ cụm duy nhất
    int wordCountIndex = 0;

    // Tách chuỗi thành các cụm từ bằng dấu cách
    char copyStr[strlen(str) + 1];
    strcpy(copyStr, str);

    char *token = strtok(copyStr, " ");
    while (token != NULL) {
        // Kiểm tra xem cụm từ đã tồn tại trong wordCounts chưa
        int foundIndex = -1;
        for (int j = 0; j < wordCountIndex; j++) {
            if (isEqual(token, wordCounts[j].word)) {
                foundIndex = j;
                break;
            }
        }
    int main() {
    const int maxLength = 100; 
    char myArray[maxLength];

    printf("Nhập vào một mảng ký tự: ");
    fgets(myArray, maxLength, stdin); // Sử dụng fgets để nhập chuỗi từ bàn phím

    countAndPrintOccurrences(myArray);

    return 0;
}
