#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


shift(int* a, int *b)
{
    int var;

    if (a>=b)
    {

        //left shift
        var << 1;

    }

    else
    {
        //right shift
        var >> 1;

    }

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

    int opt;

    while (getopt(argc, argv, ":hw:H:o:r:g:b:") != -1)

    {
        switch (opt)
        {
        //print help and exit
        case 'h':
            printf("The following arguments are eligible for usage: blahblahblah\n");
            exit(EXIT_FAILURE);

        //define width
        case 'W':

            width_found = true;
            break;

        //define height
        case 'H':

            height_found = true;
            break;

        //define filename
        case 'o':

            filename_found = true;
            break;

        //define red value
        case 'r':

        //define green value
        case 'g':

        //define blue value
        case 'b':

        //print a message if any unknown commands are found
        case '?':
            printf("The following option you provided is unknown: %c\n", optopt);
            break;

        }

        int x,y;

        for (y=0; y<height; y++)
        {


            for (x=0; x<width; x++)
            {
                int red   = (shift(x,rx) ^ shift(y,ry)) & 0xff;
                int green = (shift(x,gx) ^ shift(y,by)) & 0xff;
                int blue  = (shift(x,bx) ^ shift(y,gy)) & 0xff;
                // write_pixel(red,green,bue);

            }
        }

        FILE* image = fopen("produced_image.ppm", "w");

        if (!image)
        {
            printf("Error! Couldn't open or create file!\n");
            exit(EXIT_FAILURE);
        }


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

    return 0;
}
