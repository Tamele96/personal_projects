#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



int isDouble(const char *str) {
    int hasDecimal = 0;
    for (; *str; ++str) {
        if (*str == '.') {
            if (hasDecimal) return 0;  // More than one decimal point
            hasDecimal = 1;
        }
        else if (!isdigit(*str)) {
            return 0;
        }
    }
    return 1;
}



int main(int argc, char*argv[])
{
    if (argc != 3)
    {
        printf("Error! Please provide 2 arguments when running the program - the first one being the desired resistance value in Ohm, the second one being the E-series.\n");
        exit(EXIT_FAILURE);
    }

    char * ptr;
    double resistor = strtod(argv[1], &ptr);

    char e_series[20];
    strcpy (e_series, argv[2]);



        if (!isDouble(argv[1])) {
            printf("Error! Your resistor value is invalid.");
        }




    return 0;
}
