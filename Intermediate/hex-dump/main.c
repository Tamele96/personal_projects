#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

char printasc();

int main(int argc, char *argv[])
{

FILE *file_to_read = NULL;

file_to_read = fopen(argv[1], "r");


 if (file_to_read == NULL)
    {
        printf("Error! Couldn't open and read the file!\n");
        exit(EXIT_FAILURE);
    }



FILE *hexdump = fopen ("hex_dump.txt" ,"w");

if (hexdump == NULL)
{
    printf("Error, couldn't find the file to dump stuff in!\n");
}


char current_bit;

int laufvariable = 0;
int eight_liner = 0;
char buffer [8];

while((current_bit = fgetc(file_to_read))!= EOF)
{

    if (eight_liner == 0)
    {
        fprintf(hexdump, "%08x  ", laufvariable);
    }

    if((isprint(current_bit) == 0) || (isspace(current_bit) != 0))
    {
        current_bit = '.';
    }


    uint8_t bit_as_int = (uint8_t)current_bit;
    fprintf (hexdump, "%3.0x ", bit_as_int);



    buffer[eight_liner]= current_bit;
    eight_liner++;

    if (eight_liner == 8)
    {
      fprintf(hexdump, "\t%.8s\n", buffer);

      for (int i=0; i<8; i++)
      {
        buffer [i] = '\0';
      }


        eight_liner = 0;
        laufvariable += 8;
    }



}

while (eight_liner != 8)
{
    fprintf(hexdump, "    ");
    eight_liner++;
}


fprintf(hexdump, "\t%s", buffer);

fclose(hexdump);

fclose(file_to_read);

    return 0;
}
