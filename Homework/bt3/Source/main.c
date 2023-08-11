#include "date.h"
#include <stdio.h>

extern const char *days[];

int main() {
    int day, month, year;

    printf("Enter day: ");
    scanf("%d", &day);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (!isValidDate(day, month, year)) {
        printf("The entered date is not valid.\n");
        return 1; // Exit with an error code
    }

    int dayOfWeek = getDayOfWeek(day, month, year);
    
    printf("The date %d/%d/%d falls on a %s.\n", day, month, year, days[dayOfWeek]);

    return 0;
}
