#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int spaces);

int main(void)
{
    // Prompts user for a height and re-prompts if not right attribute
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Makes a triangle according to height variable
    if (height > 1)
    {
        for (int i = 0; i < height; i++)
        {
            print_row(i + 1, height - i - 1);
            printf("\n");
        }
    }
    else
    {
        printf("#\n");
    }
}

// Prints every row
void print_row(int bricks, int spaces)
{
    // Print spaces, each row has height - 1 spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // Print rows, each row has i bricks
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
}
