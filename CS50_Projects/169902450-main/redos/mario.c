/*
Code written by Katherina Dayaon
08/24/24
More comfortable version of mario.c
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get height from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);
    int spaces = height - 1;

    //print based on height
    for (int i = 0; i < height; i++)
    {
        //print based on length
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
        spaces--;
    }

}
