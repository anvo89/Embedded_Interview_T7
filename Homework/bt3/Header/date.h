#ifndef DATE_H
#define DATE_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Week;

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

typedef struct {
    uint8_t day;
    Month month;
    uint16_t year;
    Week week;
} Date;

bool isValidDate(int day, int month, int year);
int isLeapYear(uint16_t year);
int getDayOfWeek(int day, int month, int year);
#endif
