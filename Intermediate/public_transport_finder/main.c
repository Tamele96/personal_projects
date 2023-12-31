#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[])
{
    bool longitude_found = false, latitude_found = false;

    double my_longitude_deg = 0;
    double my_latitude_deg = 0;

    double my_longitude_rad = 0;
    double my_latitude_rad = 0;

    double min_distance = 40100000;

    //Error checking for enough arguments
    if (argc < 5)

    {
        printf("Error! Not enough arguments provided!\n");
        exit(EXIT_FAILURE);
    }


    //open file stops.txt
    FILE * stops = fopen("stops.txt", "r");

    //Error check in case the file can't open
    if (!stops)
    {
        printf("Error! Couldn't open stops.txt!\n");
        exit(EXIT_FAILURE);
    }


    //check for longitude and latitude argument
    int opt = -1;

    while ((opt = getopt(argc, argv, ":l:b:")) != -1)

    {

        char *endptr;

        switch(opt)
        {

        case 'l':

            endptr = optarg;

            my_longitude_deg = strtod(optarg, &endptr);

            if (*endptr != '\0')
            {
                printf("Error! The given value for longitude is not valid!\n");
                exit(EXIT_FAILURE);

            }

            my_longitude_rad =(my_longitude_deg/180) * M_PI;


            longitude_found = true;

            break;


        case 'b':

            endptr = optarg;

            my_latitude_deg = strtod(optarg, &endptr);

            if (*endptr != '\0')
            {
                printf("Error! The given value for latitude is not valid!\n");
                exit(EXIT_FAILURE);
            }


            my_latitude_rad =(my_latitude_deg/180) * M_PI;


            latitude_found = true;

            break;

        default:

            printf("Error, please provide longitude and latitude when running the program!\n");

        }

    }




    if(longitude_found == false || latitude_found == false)

    {
        printf("Error, either longitude or latitude were not found within the given arguments!\n");
        exit(EXIT_FAILURE);
    }

    char header [200];


    fgets(header, 200, stops);

    if (strncmp(header, "stop_id,stop_name,stop_lat,stop_lon", 10) != 0)
    {
        printf("Error! File does not start with the expected header line!\n");
        exit(EXIT_FAILURE);
    }





    char nearest_stop_name [100];


    double latitude_deg = 0;
    double longitude_deg = 0;

    double latitude_rad = 0;
    double longitude_rad = 0;





    char line [1000];

    int line_counter = 2;

    while (fgets(line, sizeof(line), stops)!= NULL)
    {


        char stop_id [100];
        char stop_name [128];
        char stop_lat [100];
        char stop_lon [100];
        char first_comma[2];
        char second_comma[2];
        char third_comma[2];

        char * context;
        char * token;

        token = strtok_s(line, "\"", &context);

        //take the stop id input
        if(token != NULL)
        {
            strncpy(stop_id, token, sizeof(stop_id)-1);
            token = strtok_s(NULL, "\"", &context);

        }
        else

        {
            printf("Error in line %d! stop_id not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }


        //take and get rid of the first comma
        if(token != NULL)
        {
            strncpy(first_comma, token, sizeof(first_comma)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! first comma not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }


        //take the stop name input
        if(token != NULL)
        {
            strncpy(stop_name, token, sizeof(stop_name)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! stop_name not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }


        //take and get rid of the second comma
        if(token != NULL)
        {
            strncpy(second_comma, token, sizeof(second_comma)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! second comma not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }



        //take the latitude input of the stop
        if(token != NULL)
        {
            strncpy(stop_lat, token, sizeof(stop_lat)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! stop_lat not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }

        //take and get rid of the third comma
        if(token != NULL)
        {
            strncpy(third_comma, token, sizeof(third_comma)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! third comma not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }


        //take the longitude input of the stop
        if(token != NULL)
        {
            strncpy(stop_lon, token, sizeof(stop_lon)-1);
            token = strtok_s(NULL, "\"", &context);
        }

        else

        {
            printf("Error in line %d! stop_lon not found.\n", line_counter);
            exit(EXIT_FAILURE);
        }


        latitude_deg = strtod(stop_lat, &context);
        longitude_deg = strtod(stop_lon, &context);

        longitude_rad =(longitude_deg/180) * M_PI;
        latitude_rad =(latitude_deg/180) * M_PI;


        double earth_radius = 6371008;


        double dlat = my_latitude_rad - latitude_rad;
        double dlon = my_longitude_rad - longitude_rad;

        double distance = 2 * earth_radius * asin(sqrt(pow(sin((dlat)/2), 2) + cos(my_latitude_rad) * cos(latitude_rad) * pow(sin((dlon)/2), 2)));



        if (distance < min_distance)
        {
            min_distance = distance;

            strncpy (nearest_stop_name, stop_name, sizeof(nearest_stop_name));
        }

        line_counter++;

    }

    printf("%s: %.0fm\n", nearest_stop_name, min_distance);


    fclose(stops);




    return 0;
}
