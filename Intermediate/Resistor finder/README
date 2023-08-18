Task specification:

Electrical resistors are only available with certain discrete values specified by the En series (E6, E12, E24).

The mth value of the desired En series can be calculated using the following formula, where d is the decade (i.e., 10, 100, 1000 etc.).
R_x=10^d⋅E(n,m)

The function E(n,m) returns the mth value of the En series, where m must lie between 0 and n-1. The following arrays may be used to implement this function:

const double E6[]  = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8, 10.0};
const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2, 10.0};
const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3,
                      3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1, 10.0};

Functional Requirements

Write a program which takes a resistance value and the desired En series as input. The program shall calculate the nearest En series value.

The program shall also output the difference to the desired resistance value both in Ohms and percent (of the desired resistance value).

If the desired resistance value is already part of the given E-series, your program shall return the value from the series with a message stating that the value was found in the given E series.
	

Use the log10() function from <math.h> to determine the desired decade(s).

E.g., if you want to find the nearest E6 value to 1999 Ohm, first decompose the value in a factor > 0 and < 10, and an exponent of 10 (a decade):

decade = (int)log(1999) -> 3
factor = 1999/pow(10,decade) -> 1.999
-> nearest E6 factor is 2.2

Interface

The program shall be executed from the command line.

It shall take two required positional command-line parameters:

    The first one shall be the desired resistance value in Ohms

    The second one shall be in the format E<number> and specify the desired E-series (e.g., E6, E12, E24)

If the program is called with too few parameters, a usage message shall be displayed.

All parameter values shall be validated (e.g., if a number is actually a number, and in its valid range).

$ rfinder.exe <Desired Resistance> <E-Series>

Example Execution

$ ./rfinder 1337 E12
Nearest E12 value:
1200 Ohms (-137 Ohms, -10.25%)

