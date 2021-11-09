#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define EPSILON 1e-11

//Makes negative numbers positive
double Abs(double y) {
    if (y < 0) {
        y = -y;
    }
    return y;
}

//Function from Piazza
double Sqrt(double x) {
    double y = 1.0;
    for (double guess = 0.0; Abs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

//Function from Piazza
double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; Abs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

//Approximates arcSin by using Taylor series expansion
double arcSin(double x) {
    bool negative = false, diff_x = false;
    // If x is close to 1 or -1, redefines x using
    // trig identity for more accurate sum.
    if (Abs(x) > .8) {
        //Stores if x is negative, the sum needs to
        //be inverted at the end if it is.
        if (x < 0) {
            negative = true;
        }
        //Stores that trig identity was used to
        //redefine x, and then redefines x
        diff_x = true;
        x = Sqrt(1 - (x * x));
    }
    double sum = x, xpower = x, fractions = 1, pterm = x, i;
    //Uses Taylor series to approximate arcSin value. Code is heavily
    //based off of code shown in Eugene's section.
    for (i = 3; Abs(pterm) > EPSILON; i += 2) {
        fractions *= ((i - 2) / (i - 1));
        xpower *= x * x;
        pterm = fractions * xpower * (1 / i);
        sum += pterm;
    }
    //If x was redefined, then does second
    //half of trig identity. Also if it was
    //negative before, flips its sign.
    if (diff_x == true) {
        sum = (M_PI / 2) - sum;
        if (negative == true) {
            sum = -sum;
        }
    }
    return sum;
}

//arcCos function just depends on the arcSin function
//because arccos(x) = (pi/2) - arcsin(x)
double arcCos(double x) {
    x = (M_PI / 2) - arcSin(x);
    return x;
}

//arcCos just based off arcSin cause trig identity
double arcTan(double x) {
    x = arcSin(x / Sqrt((x * x) + 1));
    return x;
}

//Approximates Log by usings newtons method.
double Log(double x) {
    double pguess = 0.0, guess = 1.0;
    //continues getting better guesses until difference between
    //previous guess and current guess is < EPSILON.
    while (Abs(guess - pguess) > EPSILON) {
        pguess = guess;
        guess = pguess - ((Exp(pguess) - x) / Exp(pguess));
    }
    return guess;
}
