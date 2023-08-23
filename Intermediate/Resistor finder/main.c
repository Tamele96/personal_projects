#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//function to check if an argument is a double

int isDouble(const char *str) {
    int hasDecimal = 0;
    for (; *str; ++str) {
        if (*str == '.') {
            if (hasDecimal) return 0;  // if more than one comma -> invalid double value
            hasDecimal = 1;
        }
        else if (!isdigit(*str)) {
            return 0;
        }
    }
    return 1;
}


//function to find the nearest value to the value of the resistor

    double findClosestDouble(double arr[], int size, double input) {
    double closest = arr[0];
    double minDiff = fabs(arr[0] - input);

    for (int i = 1; i < size; i++) {
        double diff = fabs(arr[i] - input);
        if (diff < minDiff) {
            closest = arr[i];
            minDiff = diff;
        }
    }

    return closest;
}


int main(int argc, char*argv[])
{
    //check if the right amount of arguments have been provided
    if (argc != 3)
    {
        printf("Error! Please provide 2 arguments when running the program - the first one being the desired resistance value in Ohm, the second one being the E-series.\n");
        exit(EXIT_FAILURE);
    }

    //check if the first argument is a double
    if (!isDouble(argv[1])) {
            printf("Error! Your resistor value is invalid.");
        }

    //Different values of the different E-series (Resistor standard values)
    const double E6[]  = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8, 10.0};
    const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2, 10.0};
    const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1, 10.0};


    //get resistor value from argument 1
    char * ptr;
    double resistor = strtod(argv[1], &ptr);

    //get E-series type from argument 2
    char e_series[20];
    strcpy (e_series, argv[2]);

    //declare the array size
    int array_size = 0;


//set the array size to the right size, depending on E-series type

    if (strcmp(e_series, "E6") == 0)

{

    array_size = sizeof(double)*7;

}

else if (strcmp(e_series, "E12") == 0)

{

    array_size = sizeof(double)*13;

}

else if (strcmp(e_series, "E24") == 0)

{

   array_size = (sizeof(double)*25);

}

//Error check
    else
{
printf("Error! Invalid E-series.\n");
}


    //create array of the right size
    double* arr = (double*)malloc(array_size);






    //find the closest existing value to the resistor arguments' value
    double closest = findClosestDouble(arr, array_size, resistor);



    return 0;
}
