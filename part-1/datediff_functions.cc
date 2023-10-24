// Jemin Song
// jeminsong@csu.fullerton.edu
// @jeminsong
// Partners: @jeminsong
//
// Program to calculate the date between two Gregorian dates.
//

#include "datediff_functions.h"

// Convert a Gregorian calendar date to a Julian day number
//
// Given a date of the form YYYY/MM/DD such as 12/25/2021, convert the
// Gregorian date to a Julian day number. The Julian day is the continuous
// count of days since the beginning of the Julian period, January 1, 4713 BCE.
// See https://en.wikipedia.org/wiki/Julian_day for more information.
//
// \param day The day of the month, valid values are 1-31
// \param month The month of the year, valid values are 1-12
// \param year The year, valid values are -4713 through 2436204
// returns the Julian day number
int JulianDay(int month, int day, int year) {
  int mon = (14 - month) / 12;
  int yar = year + 4800 - mon;
  int mos = month + (12 * mon) - 3;
  int day_term = day + (153 * mos + 2) / 5;
  int year_term = 365 * yar + yar / 4 - yar / 100 + yar / 400;
  int jdate = day_term + year_term - 32045;
  return jdate;
}

// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int start_jd = JulianDay(start_month, start_day, start_year);
  int end_jd = JulianDay(end_month, end_day, end_year);
  return end_jd - start_jd;
  return 0;
}

void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}