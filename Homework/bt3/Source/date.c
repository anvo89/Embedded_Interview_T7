#include "date.h"

const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int isLeapYear(uint16_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 0) {
        return false; // Negative year is not valid
    }

    if (month < JANUARY || month > DECEMBER) {
        return false; // Invalid month
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]) {
        return false; // Invalid day for the given month
    }

    return true;
}

int getDayOfWeek(int day, int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    int totalDays = 0;
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += day;

    int dayOfWeek = (totalDays + year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;

    return dayOfWeek;
}
