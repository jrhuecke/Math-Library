#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define OPTIONS "asctl"

//Prints out the table of my arcSin values compared to the math library's value.
//Takes nothing as input.
void arc_sin_table() {
    printf("  x            arcSin           Library        Difference  \n");
    printf("  -            ------           -------        ----------  \n");
    for (double k = -1; k <= 1; k += 0.1) {
        printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", k, arcSin(k), asin(k), arcSin(k) - asin(k));
    }
    return;
}

//Prints out the table of my arcCos values compared to the math library's value.
//Takes nothing as input.
void arc_cos_table() {
    printf("  x            arcCos           Library        Difference  \n");
    printf("  -            ------           -------        ----------  \n");
    for (double k = -1; k <= 1; k += 0.1) {
        printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", k, arcCos(k), acos(k), arcCos(k) - acos(k));
    }
    return;
}

//Prints out the table of my arcTan values compared to the math library's value.
//Takes nothing as input.
void arc_tan_table() {
    printf("  x            arcTan           Library        Difference  \n");
    printf("  -            ------           -------        ----------  \n");
    for (double k = 1; k <= 10; k += 0.1) {
        printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", k, arcTan(k), atan(k), arcTan(k) - atan(k));
    }
    return;
}

//Prints out the table of my Log values compared to the math library's value.
//Takes nothing as input.
void log_table() {
    printf("  x            Log              Library        Difference  \n");
    printf("  -            ------           -------        ----------  \n");
    for (double k = 1; k <= 10; k += 0.1) {
        printf(" %7.4lf % 16.8lf % 16.8lf % 16.10lf\n", k, Log(k), log(k), Log(k) - log(k));
    }
    return;
}

int main(int argc, char **argv) {
    int opt = 0;
    bool all_ran = false, arc_sin_ran = false, arc_cos_ran = false, arc_tan_ran = false,
         log_ran = false;
    //Reads through all the command-line options and saves which ones were entered.
    //Does not run the functions right away due to wanting to always have the command
    //line options run in the same order regardless of how they were entered.
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': all_ran = true; break;
        case 's': arc_sin_ran = true; break;
        case 'c': arc_cos_ran = true; break;
        case 't': arc_tan_ran = true; break;
        case 'l': log_ran = true; break;
        }
    }
    //Now runs the functions for the tables based on which options were entered.
    //Program ends before running through the other if statements if the 'all'
    //option is entered due to not wanting to repeat tables.
    if (all_ran == true) {
        arc_sin_table();
        arc_cos_table();
        arc_tan_table();
        log_table();
        return 0;
    }
    if (arc_sin_ran == true) {
        arc_sin_table();
    }
    if (arc_cos_ran == true) {
        arc_cos_table();
    }
    if (arc_tan_ran == true) {
        arc_tan_table();
    }
    if (log_ran == true) {
        log_table();
    }
    return 0;
}
