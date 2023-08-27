#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//function to check if an argument is a double
int isDouble(const char* str)
{
    char* endptr;
    strtod(str, &endptr);

    if (endptr == str || *endptr != '\0')
    {
        printf("Error! The resistor value you entered is not a valid double.\n");
        return 0;
    }

    return 1;
}


//function to find the nearest value to the value of the resistor
double findClosestDouble(double arr[], int size, double input)
{
    double closest = arr[0];
    double minDiff = fabs(arr[0] - input);

    for (int i = 1; i < size; i++)
    {
        double diff = fabs(arr[i] - input);
        if (diff < minDiff)
        {
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
    if (!isDouble(argv[1]))
    {
        printf("Error! Your resistor value is invalid.");
        exit(EXIT_FAILURE);
    }

    //Different values of the different E-series (Resistor standard values)
    const double E6[]  = {1.0, 1.5, 2.2, 3.3, 4.7, 6.8, 10.0};
    const double E12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2, 10.0};
    const double E24[] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1, 10.0};


    //get resistor value from argument 1
    char * ptr;
    double resistor = strtod(argv[1], &ptr);

    //get E-series type from argument 2
    char* e_series_type = malloc(strlen(argv[2])+1);
    strcpy (e_series_type, argv[2]);

    //declare the array size
    int array_size = 0;

    double* e_series = NULL;

    //set the array size to the right size, depending on E-series type
    if (strcmp(e_series_type, "E6") == 0)
    {
        array_size = 7;
        e_series = malloc(sizeof(double) * array_size);
        memcpy(e_series, E6, sizeof(double) * array_size);
    }

    else if (strcmp(e_series_type, "E12") == 0)
    {
        array_size = 13;
        e_series = malloc(sizeof(double) * array_size);
        memcpy(e_series, E12, sizeof(double) * array_size);
    }

    else if (strcmp(e_series_type, "E24") == 0)
    {
        array_size = 25;
        e_series = malloc(sizeof(double) * array_size);
        memcpy(e_series, E24, sizeof(double) * array_size);
    }

    else
    {
        printf("Error! Invalid E-series.\n");
        exit(EXIT_FAILURE);
    }


    //create array of the right size
    double* arr = e_series;

    for (int i=0; i<array_size; i++)
    {
        arr[i] = e_series[i];
    }


    //calculate the decade of the resistor value
    int decade = (int)log10(resistor);

    // calculate the factor of the resistor value
    double factor = resistor/(pow(10,decade));


    //find the closest existing value to the resistor arguments' value
    double closest = findClosestDouble(arr, array_size, factor);

    if ((1000*closest) == resistor)
    {
        printf("The resistor value %.0f was found amongst the values of the given E-series.\n", resistor);

    }

    else
    {
    //creating variables for easier result printing
    double nearest = closest*1000;
    double difference = nearest - resistor;
    double percentage = (100*difference)/resistor;


    //print result
    printf ("The closest resistor value to %.1f Ohms is:\n%.0f Ohms (%f Ohms, %f%%)\n", resistor, nearest, difference, percentage);
}

    //free the used memory
    free(e_series_type);

    return 0;
}
