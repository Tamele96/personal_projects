#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Pokeball 200
#define Band_Price 10000
#define gender_pick 5000


int main()
{
    while (1)
    {

    int female_mon = 0;
    int male_mon = 0;
    int female_cost = 0;
    int male_cost = 0;
    int how_many_ivs = 0;
    int result = 0;
    int pokemon_needed = 0;
    int necessary_breeds = 0;
    int breeding_bands = 0;

    //----------------------------------------

    printf("What is the average cost of your Pokemon (female))?\n");
    scanf("%d", &female_mon);

    printf("What is the average cost of your male of same egg group?\n");
    scanf("%d", &male_mon);

    printf("How many perfect IV's do you want your Pokemon to have?\n");
    scanf("%d", &how_many_ivs);


    //----------------------------------------

    for (int i=0; i<how_many_ivs; i++)
    {
        necessary_breeds += i;

    }

    breeding_bands = necessary_breeds * 2;

    //----------------------------------------

    pokemon_needed = pow(2,how_many_ivs-1);
    female_cost = (pokemon_needed/2)*female_mon;
    male_cost = (pokemon_needed/2)*male_mon;

    result = female_cost + male_cost + necessary_breeds * Pokeball + breeding_bands * Band_Price + necessary_breeds * gender_pick;


    //----------------------------------------
    printf("///////////////////////////////////////////////////////////\n");
    printf("Your total cost to breed the desired Pokemon will be: %d\n", result);
    printf("///////////////////////////////////////////////////////////\n\n");
    }

    return 0;
}
