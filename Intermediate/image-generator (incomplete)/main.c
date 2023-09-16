#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int shift(int* a, int* b)
{


    if (*b>=0)
    {

        //left shift
        *a << *b;

    }

    else
    {
        //right shift
        *a >> abs(*b);

    }

    return *a;

}


int main(int argc, char * argv[])

{

    if (argc < 2)
    {
        printf("Error! You must provide at least 2 arguments: the height and the width of the image to be generated.\nRun the program with -h for further instructions.\n");
        exit(EXIT_FAILURE);
    }

    int height=0, width=0, rx=0, gx=0, bx=0, ry=0, gy=0, by=0, red=0, green=0, blue=0;

    bool height_found = false, width_found = false, filename_found = false;

    char filename[FILENAME_MAX];

    int opt = -1;

    while (getopt(argc, argv, ":hw:H:o:r:g:b:") != -1)

    {

        char *endptr;
        switch (opt)
        {
        //print help and exit
        case 'h':
            printf("The following arguments are eligible for usage: blahblahblah\n");
            exit(EXIT_FAILURE);

        //define width
        case 'W':

            endptr = optarg;

            width = strtod(optarg, &endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for width is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            width_found = true;
            break;


        //define height
        case 'H':

            *endptr = optarg;

            height = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }


            height_found = true;
            break;

        //define filename
        case 'o':

            strncpy(filename, optarg, 10);

            filename_found = true;
            break;



        //define red value
        case 'r':

            *endptr = optarg;

            rx = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }


        case 'R':

            *endptr = optarg;

            ry = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }



        //define green value
        case 'g':

            *endptr = optarg;

            gx = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

        case 'G':

            *endptr = optarg;

            gy = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }



        //define blue value
        case 'b':

            *endptr = optarg;

            bx = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

        case 'B':

            *endptr = optarg;

            by = strtod(optarg, endptr);

            if(endptr != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }



        //print a message if any unknown commands are found
        case '?':
            printf("The following option you provided is unknown: %c\n", optopt);
            break;


        //default message, if no inputs
        default:
            printf("Error! No commands have been found. Run the program with -h for instructions on how to use it.\n");

        }

        int x,y;

        for (y=0; y<height; y++)
        {


            for (x=0; x<width; x++)
            {
                red   = (shift(x,rx) ^ shift(y,ry)) & 0xff;
                green = (shift(x,gx) ^ shift(y,by)) & 0xff;
                blue  = (shift(x,bx) ^ shift(y,gy)) & 0xff;
                // write_pixel(red,green,bue);

            }
        }


        //checking if there is a valid filename, width and height
        if (filename_found && width_found && height_found)
        {


            //open the file

            FILE* image = fopen(filename, "w");

            if (!image)
            {
                printf("Error! Couldn't open or create file!\n");
                exit(EXIT_FAILURE);
            }


            fprintf(image, "P3\n");
            fprintf(image, "%d %d\n", width, height);
            fprintf(image, "255\n");


            for (int i=0; i<height; i++)
            {

                fprintf(image, "%d %d %d", red, green, blue);
                if(i != height-1)
                {
                    fprintf(image, "\n");

                }
            }


            fclose(image);
        }
    }

    return 0;
}
