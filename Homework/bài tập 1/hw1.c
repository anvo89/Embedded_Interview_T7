#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

        if (foundIndex != -1) {
            // Nếu cụm từ đã tồn tại, tăng số lần xuất hiện của nó
            wordCounts[foundIndex].count++;
        } else {
            // Nếu cụm từ chưa tồn tại, thêm nó vào mảng nếu chưa đạt số lượng tối đa
            if (wordCountIndex < MAX_WORDS) {
                wordCounts[wordCountIndex].word = token;
                wordCounts[wordCountIndex].count = 1;
                wordCountIndex++;
            } else {
                printf("Đã đạt tối đa số lượng từ cụm duy nhất\n");
            }
        }

        token = strtok(NULL, " "); //Gán con trỏ về NULL khi không còn từ cụm nào còn lại để tách.
    }

    // In ra những từ trùng lặp nhiều hơn 1 lần và 1 lần
    
    for (int i = 0; i < wordCountIndex; i++) {
        if (wordCounts[i].count > 1||wordCounts[i].count == 1) {
            printf("Số lần xuất hiện của %s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
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
