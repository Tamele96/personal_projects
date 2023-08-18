#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compare characters for qsort.
int compare(const void * a, const void * b)
{
    return *(char*)a - *(char*)b;
}

// Function to sort a string alphabetically.
void sort_string(char* str)
{
    int length = strlen(str);
    qsort(str, length, sizeof(char), compare);
}


int main(int argc, char** argv)
{

    //Error check
    if (argc != 3)
    {
        printf("Error! Please provide 2 Arguments when starting the program - The first one being the word, the second one being the dictionary.\n");
        exit(EXIT_FAILURE);
    }


    char* word = strdup(argv[1]);


    char original_word[256];
    strcpy(original_word, word);

    //convert word to lowercase
    for(int i = 0; i<strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }

char word_but_in_lower[256];

strcpy(word_but_in_lower, word);
    sort_string(word);



    char* dictionary = argv[2];

    FILE * wordcounting = fopen(dictionary, "r");

    if (wordcounting == NULL)
    {
        printf("Error! Unable to open the file %s. Check the spelling of the file and make sure it is in the same folder.\n", dictionary);
        exit(EXIT_FAILURE);
    }


    printf("Hier sind alle Anagramme des Wortes %s, die in der Liste %s vorkommen:\n\n", original_word, argv[2]);

    char buffer[BUFFER_SIZE];


    while(fgets(buffer, BUFFER_SIZE, wordcounting) != NULL)
    {


        if (strcspn(buffer, "\n") == (strlen(buffer)-1))
        {

            for(int j=0; j<(strlen(buffer)-2); j++)
            {

                if(isalpha(buffer[j]) == 0)
                    break;

            }


            // Remove "\n"
            buffer[strcspn(buffer, "\n")] = '\0';


            for (int k=0; k<(strlen(buffer)); k++)
            {

                buffer[k]= tolower(buffer[k]);

            }

            if (strcmp(buffer, word_but_in_lower) != 0)

            {

                char sorted_line[256];
                strcpy(sorted_line, buffer);
                sort_string(sorted_line);  // Sort the dictionary word alphabetically.

                if(strcmp(word, sorted_line) == 0)
                {
                    printf("%s\n", buffer);
                }
            }


        }

        else
        {
            printf("Error. One of the lines didn't fit into the buffer!\n");
            exit(EXIT_FAILURE);

        }
    }



    fclose (wordcounting);


    return 0;
}
