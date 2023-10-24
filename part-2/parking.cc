// TODO: Add the required header

#include <iostream>
#include <string>
#include <vector>

#include "parking_functions.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};

  // TODO: write an if statement that validates the number of arguments. If
  // the number of arguments is invalid, print
  // error: you must supply four arguments
  // and return non-zero.

  // TODO: declare a string variable to hold the first argument (street)

  // TODO: declare a string variable to hold the second argument (day)

  // TODO: declare an int variable to hold the third argument (hour)
  // HINT: use the std::stoi function to convert the string argument to an int.

  // TODO: declare an int variable to hold the fourth argument (minute)
  // HINT: use the std::stoi function to convert the string argument to an int.

  // TODO: write an if statement that validates the street.
  // If the street is invalid, print
  // error: invalid street
  // and return non-zero.

  // TODO: write an if statement that validates the day.
  // If the day is invalid, print
  // error: invalid day
  // and return non-zero.

  // TODO: write an if statement that validates the hour.
  // If the hour is invalid, print
  // error: invalid hour
  // and return non-zero.

  // TODO: write an if statement that validates the minute.
  // If the minute is invalid, print
  // error: invalid minute
  // and return non-zero.

  // TODO: Declare a bool variable that will store true when parking is
  // allowed, or false when not allowed.

  // TODO: write an if-else-chain that uses the day to decide which
  // function to call (CanParkOnAsh, etc.)
  // Call the chosen function, and assign the return value into your bool
  // variable.

  // TODO: Write an if statement that prints
  // allowed
  // or 
  // not allowed
  // according to the value in your bool variable.

  return 0;
}