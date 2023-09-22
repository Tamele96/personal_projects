#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

int shift(int a, int b)
{


    if (b>=0)
    {

        //left shift
       a = a << b;

    }

    else
    {
        //right shift
       a = a >> abs(b);

    }

    return a;

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



    while ((opt = getopt(argc, argv, ":hW:H:o:r:R:g:G:b:B:")) != -1)


    {

        char *endptr;


        switch (opt)
        {

        //print help and exit
        case 'h':
            printf("The following arguments are eligible for usage:\n\n-W to set the width of the image\n-H to set the height of the image\n-o to determine the filename\t\
                   \n-r to set the red value for the x coordinates of the image\n-R to set the red value for the y coordinates of the image\t\
                   \n-g to set the green value for the x coordinates of the image\n-G to set the green value for the y coordinates of the image\t\
                   \n-b to set the blue value for the x coordinates of the image\n-B to set the blue value for the y coordinates of the image\t\
                   \n\nWidth, Height and the file name are required for your image, whereas the colour values are optional.\n");
                exit(EXIT_FAILURE);

        //define width
        case 'W':

            endptr = optarg;

            errno = 0;

            width = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for width is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            width_found = true;
            break;


        //define height
        case 'H':

            endptr = optarg;

            errno = 0;

            height = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for height is not a valid number.\n");
                exit(EXIT_FAILURE);
            }


            height_found = true;
            break;

        //define filename
        case 'o':

            strncpy(filename, optarg, FILENAME_MAX);

            filename_found = true;
            break;



        //define red value
        case 'r':

            endptr = optarg;

            errno = 0;

            rx = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for rx is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            break;

        case 'R':

            endptr = optarg;

            errno = 0;

            ry = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for ry is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            break;


        //define green value
        case 'g':

            endptr = optarg;

            errno = 0;

            gx = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for gx is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            break;

        case 'G':

            endptr = optarg;

            errno = 0;

            gy = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for gy is not a valid number.\n");
                exit(EXIT_FAILURE);
            }


            break;


        //define blue value
        case 'b':

            endptr = optarg;

            errno = 0;

            bx = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for bx is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            break;

        case 'B':

            endptr = optarg;

            errno = 0;

            by = strtol(optarg, &endptr, 10);

            if(errno != 0)
            {

                printf("Error! The expected value for by is not a valid number.\n");
                exit(EXIT_FAILURE);
            }

            break;


        //print a message if any unknown commands are found
        case '?':
            printf("The following option you provided is unknown: %c\n", optopt);
            break;


        //default message, if no inputs
        default:
            printf("Error! No commands have been found. Run the program with -h for instructions on how to use it.\n");

        }




}
        //checking if there is a valid filename, width and height
        if (filename_found && width_found && height_found)
        {




        //check if the filename ends in ".ppm"
        int filename_length = (strlen(filename));

        if(filename_length <= 4 || strncmp((filename + filename_length - 4), ".ppm", FILENAME_MAX) != 0)
        {
            printf("Error with the filename, please check that it ends with .ppm!\n");

        }



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

            // write pixels
            for (int y=0; y<height; y++)
            {

                for(int x=0; x<width; x++)

                {

                red   = (shift(x,rx) ^ shift(y,ry)) & 0xff;
                green = (shift(x,gx) ^ shift(y,gy)) & 0xff;
                blue  = (shift(x,bx) ^ shift(y,by)) & 0xff;

                fprintf(image, "%d %d %d ", red, green, blue);

                }

                if(y != (height-1))
                {
                    fprintf(image, "\n");

                }
            }


            fclose(image);
        }

        else
            {
            printf("Error! The program needs at least a value for height, width and a filename to run.\n");
        }




    return 0;
}
