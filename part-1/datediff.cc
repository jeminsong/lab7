// Jemin Song
// jeminsong@csu.fullerton.edu
// @jeminsong
// Partners: @jeminsong
//
// Program to calculate the date between two Gregorian dates.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "datediff_functions.h"

// Main function - the entry point to our program
int main(int argc, char* argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};

  // Convert argv into a std::vector<std::string> using the
  // pattern described in lecture. Name the std::vector<std::string>
  // arguments.

  if (arguments.size() < 7) {
    std::cout
        << "Please provide a starting date and an ending date. Exiting.\n";
    return 1;
  }
  // Check to make sure there are enough arguments provided on the
  // command line. If there are too few arguments, print the error message
  // "Please provide a starting date and an ending date. Exiting.\n"
  // and exit with a return code of 1.

  int start_month{0};
  int start_day{0};
  int start_year{0};
  int end_month{0};
  int end_day{0};
  int end_year{0};

  // Declare three integer variables and initialize them to zero.
  // Name the variables start_month, start_day, start_year.

  // For the std::string values at location 1, 2, and 3 in the
  // std::vector arguments, use std::stoi() to convert the string to
  // an integer.
  start_month = std::stoi(arguments[1]);
  start_day = std::stoi(arguments[2]);
  start_year = std::stoi(arguments[3]);

  // Convert and assign the argument at location 1 to start_month.
  // Convert and assign the argument at location 2 to start_day.
  // Convert and assign the argument at location 3 to start_year.

  // Declare three integer variables and initialize them to zero.
  // Name the variables end_month, end_day, end_year.

  // For the std::string values at location 4, 5, and 6 in the
  // std::vector arguments, use std::stoi() to convert the string to
  // an integer.
  end_month = std::stoi(arguments[4]);
  end_day = std::stoi(arguments[5]);
  end_year = std::stoi(arguments[6]);

  // Convert and assign the argument at location 4 to end_month.
  // Convert and assign the argument at location 5 to end_day.
  // Convert and assign the argument at location 6 to end_year.

  // Declare an integer variable named number_days. Initialize the
  int number_days = DateDifference(start_month, start_day, start_year,
                                   end_month, end_day, end_year);
  // variable to the return value of DateDifference(). Call DateDifference()
  // with the start_month, start_day, start_year, end_month, end_day, end_year.

  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << number_days << " days "
            << ".\n";
  return 0;
}
