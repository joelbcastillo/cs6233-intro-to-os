#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isLeapYear(int year) {
  if ( year % 4 != 0 ) {
    return false;
  } else if ( year % 100 != 0 ) {
    return true;
  } else if (year % 400 != 0) {
    return false;
  }
  else {
    return true;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    int year = atoi(argv[1]);
    bool leapYear = isLeapYear(year);
    if (leapYear) {
      printf( "%d is a leap year\n", year);
    } else {
      printf( "%d is not a leap year\n", year);
    }
  } else {
    printf("No args");
  }
  return 0;
}