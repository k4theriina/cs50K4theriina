#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("hello world!\n");
    string name = get_string("What's your name? ");
    if (name == "david")
    {
            printf("hi %s\n", name);
    }
    else
    {
            printf("YOU ARE UGLY! %s/n", name);
    }
}
