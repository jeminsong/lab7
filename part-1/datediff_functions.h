// Jemin Song
// jeminsong@csu.fullerton.edu
// @jeminsong
// Partners: @jeminsong
//
// Program to calculate the date between two Gregorian dates.
//

#include <iostream>

#ifndef DATEDIFF_FUNCTIONS
#define DATEDIFF_FUNCTIONS

int JulianDay(int month, int day, int year);

int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year);

void PrintDate(int month, int day, int year);

#endif
