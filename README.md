## Assignment 2: A Small Numerical Library:

    This program consists of several different files with the
    combined purpose of comparing mathematical functions I created
    to those provided by the math.h library. The program takes
    command-lines options as input and then prints out a table
    of the requested function(s). The tables consists of 4 columns:
    the x value, my function's output, the math library's output, and
    the difference between the two.

## How to Build:

    Typing 'make' builds the program, 'make clean' removes any files
    created when it is compiled, and 'make clang-format' formats the
    files if there is a given .clang-format file.

## How to Run:

    To run the program type './mathlib-test' followed by desired
    command-line options. Each functions table will only be printed
    once, even if it is requested mulitple times in the input.

    For example:  ./mathlib-test -s -t

    The accepted command-line options are:

    -a   Prints all of the tables
    -s   Prints the table for arcSin
    -c   Prints the table for arcCos
    -t   Prints the table for arcTan
    -l   Prints the table for Log

--------------------------------------------------------------------
