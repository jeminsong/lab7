
# What to Do
1. Read the entire README with your partner before doing anything else.
1. With your partner, edit the `datediff.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code. Remember, make small changes and compile often.
1. Your program must use the `JulianDay`, `DateDifference`, and `PrintDate` functions. Do not change the prototypes of these functions (name, return type, argument types).
1. Compile your program with the `make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `./datediff` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Check your header with the `make header` shell command. Correct any errors.
1. Check for format errors with the `make format` shell command. Correct any errors.
1. Check for lint errors with the `make lint` shell command. Correct any errors.
1. Test your program against automated test with the `make test` command. Debug any runtime errors or logic errors using the same procedures.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

# Date Difference

Remember the Date Difference program from a previous lab? In that exercise, the program prompted the computer user for two dates, a start date and an end date, and then calculated the number of days between those two dates. The program prompted the computer user to enter the two dates by entering the month, day, and year as separate integer values. Ultimately, the program prompted the computer user for 6 different values.

In this iteration of the program, we will use the command line to enter the start and end date. Instead of prompting for each individual value, we'll write the program so the computer user can write one long command and immediately get the answer.

The original program ran like this:
```
$ ./datediff 
Enter a start month: 1
Enter a start day: 1
Enter a start year: 2022

Enter an end month: 1
Enter an end day: 1
Enter an end year: 2023

The number of days between 1/1/2022 and 1/1/2023 is 365 days.
```

And our improved version will run like this:
```
$ ./datediff 1 1 2022 1 1 2023
The number of days between 1/1/2022 and 1/1/2023 is 365 days.
```

Just like the previous program, our new program expects two dates in the [Gregorian Calendar](https://en.wikipedia.org/wiki/Gregorian_calendar).

Thanks to [Fliegel & Van Flandern](https://dl.acm.org/doi/pdf/10.1145/364096.364097), there is a very compact formula to take a given date in the Gregorian calendar and convert it to an integer that represents the number of days since day zero. This is called a [Julian Day](https://en.wikipedia.org/wiki/Julian_day). In their algorithm, day zero is November 24, 4713 [BCE](https://en.wikipedia.org/wiki/Common_Era)! This means that we can very easily calculate date differences from November 24, 4713 BCE to some where past the year 5,000,000 with `int` types.

With this information in hand, we can convert a given date to a Julian Day and then take the difference between the two Julian Days to know the number of days between them.

Fliegel & Van Flandern's algorithm is [restated on the Julian Day Wikipedia page](https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation) with some slight modifications. Below is a modestly modified line of code from the [US Naval Obervatory's NOVAS](https://github.com/indigo-astronomy/novas) source code which calculates a Julian Day (`int`) from a Gregorian Date, for example 1/23/2021 where 1 is the month January, 23 is the 23rd day of the month and 2021 is the year.

```C++
int month = 1;
int day = 23;
int year = 2021;
int julian_day = day - 32075 + 1461
      * (year + 4800 + (month - 14) / 12) / 4
      + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
      * ((year + 4900 + (month - 14) / 12) / 100) / 4;
```

This is a long formula with many expressions. Before you start blaming the computer for _doing things wrong_, double check your work. Make sure you have all the operations and parentheses in the right places. A small typo can make a big difference in the result.

To help you test your work, we know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323. Additional examples are in the section _Example Input and Output_.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

Each date will be specified on the command line. An example command will look like `./datediff 1 1 2022 1 1 2023`. This command is calculating the number of days between 1/1/2022 and 1/1/2023. The first three numbers represent the start date and the last three represent the end date.

Command line arguments are passed to our program from the operating system. The operating system stores the entire command line in a variable named `argv`. This variable is in an old-fashion type that we do not want to use so we convert it to a modern C++ `std::vector`.

For example, the following program demonstrates converting the command line arguments in `argv` into a `std::vector` named `arguments`.

```C++
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};
  return 0;
}
```

If our program is executed with the following command, `./datediff 1 1 2022 1 1 2023`, then we know that the the vector `arguments` will store the command line like this:
```
{"./datediff", "1", "1", "2022", "1", "1", "2023"}
```
Notice that everything in `arguments` is stored as a string. To convert the values to an integer, we use the C++ standard library function `std::stoi()` which converts strings to integers. For example, to convert the start date into three integers, the program may look a little like the following:

```C++
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};
  int start_month{std::stoi(arguments.at(1))};
  int start_day{std::stoi(arguments.at(2))};
  int start_year{std::stoi(arguments.at(3))};
  
  return 0;
}
```

## Requirements

Use command line arguments to gather input from the computer user. Do not use `std::cin`. The structure of the command line is the following:
```
./datediff start_month start_day start_year end_month end_day end_year
```

Use the standard C++ library function `std::stoi()` to convert strings to integer where needed.

Use the Fliegel & Van Flandern's algorithm to convert two dates into Julian Days and then take the difference. Only `int` types can be used to perform the calculations. Do not use `float` or `double`.

You shall use [std::cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

The program reads in six values from the command line, stores them in at least six different variables and then prints out a message summarizing the data and the resulting calculation.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section _Example Input and Output_ below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Functions

The main goal of this exercise is for you to practice writing function definitions. The starter code has four functions that you need to complete.

As you develop your functions, you can use the `make unittest` target to verify that your functions meet the requirements for this lab. Make sure you functions pass the unit tests before attempting to test the entire program.

### `JulianDay`

```C++
// Given a month, day, and year, calculate the Julian day number using the
// Fliegel & Van Flandern equation.
int JulianDay(int month, int day, int year)
```

### `DateDifference`

```C++
// Return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year)
```

### `PrintDate`

```C++
// Print the given date to standard output in the format MM/DD/YYYY
void PrintDate(int month, int day, int year)
```

### `main`

As usual, you need to complete the program's `main` function. This is the last of the four functions.

## Example Input and Output

The input and output of your program should match the following.

```
$ ./datediff 1 1 2020 1 1 2021
The number of days between 1/1/2020 and 1/1/2021 is 366 days.
$ ./datediff 1 1 1990 1 1 2021
The number of days between 1/1/1990 and 1/1/2021 is 11323 days.
```

## Test Cases

As usual, test your program against the test suite below.

| Test Case | Input                      | Expected Output                                                       |
|-----------|----------------------------|-----------------------------------------------------------------------|
| 1         | 1, 1, 2022, 1, 1, 2023     | `The number of days between 1/1/2022 and 1/1/2023 is 365 days.`        |
| 2         | 1, 1, 1984, 1, 1, 1985     | `The number of days between 1/1/1984 and 1/1/1985 is 366 days.`        |
| 3         | 12, 25, 1275, 12, 25, 2522 | `The number of days between 12/25/1275 and 12/25/2522 is 455457 days.` |
| 4         | 9, 21, 2022, 10, 31, 1980  | `The number of days between 9/21/2022 and 10/31/1980 is -15300 days.`  |
| 5         | 10, 1, 79, 9, 23, 2022     | `The number of days between 10/1/79 and 9/23/2022 is 709658 days.`     |

After you have performed your own testing, use `make test` to run one final automated test. Passing the tests in `make test` shall give you an clear indication if you have met the lab's requirements.

## Next Steps

After you have pushed your code to GitHub, please start on part-2.
