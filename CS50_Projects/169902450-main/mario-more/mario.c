#include <stdio.h>
#include <cs50.h>

void print_blocks1(int bricks, int spaces);
void print_blocks2(int bricks, int spaces);

int main(void)
{
    // prompts the user for input on pyramid height, reprompts if not suitable
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    //creates rows of bricks
    //creates columns of bricks
    int spaces = height - 1;
    int bricks = 1;
    for (int i = 0; i < height; i++)
    {
        print_blocks1(bricks, spaces);
        printf("  ");
        if (i == height)
        {
            print_blocks2(bricks, -1);
        }
        else
        {
            print_blocks2(bricks, 0);
        }
        printf("\n");
        spaces--;
        bricks++;
    }
}

void print_blocks1(int bricks, int spaces)
    {
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        for (int j = 0; j < bricks; j++)
        {
            printf("#");
        }
    }

void print_blocks2(int bricks, int spaces)
    {
        for (int j = 0; j < bricks; j++)
        {
            printf("#");
        }
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
    }
