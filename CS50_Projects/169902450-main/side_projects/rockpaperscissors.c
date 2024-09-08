/*
Katherina Dayaon
08.27.24
Rock Paper Scissors Program
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //initialize variables
    char comp_choice;
    const int UPPERBOUND = 100;

    //make computer choose a random number
    int random = rand() % (UPPERBOUND + 1);

    //make computer choice stone, paper, or scissors

    //if number is 0-33, make it stone
    if (random >= 0 && random < 34)
    {
        comp_choice = 's';
    }

    //if number is 33-66, make it paper
    if (random > 33 && random < 67)
    {
        comp_choice = 'p';
    }

    //if number is 66-100, make it paper
    if (random > 66 && random < 101)
    {
        comp_choice = 'z';
    }

    // Ask about choice
    printf("Enter s for STONE, p for PAPER, and z for SCISSORS");

    

    return 0;


}
