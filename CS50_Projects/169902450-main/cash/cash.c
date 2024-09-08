#include <stdio.h>
#include <cs50.h>

int get_coins( int coins, int change, int amount);

int main(void)
{
    // Prompts user for how much change is owed
    int coins = 0;
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    //Takes a bite of the change with quarters
    if (change >= 25)
    {
        int quarters = 0;
        quarters = get_coins(quarters, change, 25);
        coins = coins + quarters;
        change = change - (quarters * 25);
    }

    //Takes a bite of the change with dimes
    if (change >= 10)
    {
        int dimes = 0;
        dimes = get_coins(dimes, change, 10);
        coins = coins + dimes;
        change = change - (dimes * 10);
    }

    //Takes a bite of the change with nickels
    if (change >= 5)
    {
        int nickels = 0;
        nickels = get_coins(nickels, change, 5);
        coins = coins + nickels;
        change = change - (nickels * 5);
    }

    //Takes a bite of the change with pennies
    if (change >= 1)
    {
        int pennies = 0;
        pennies = get_coins(pennies, change, 1);
        coins = coins + pennies;
        change = change - pennies;
    }

    //prints out how many coins user needs
    printf("%d\n", coins);

}

//function for determining coins
int get_coins( int coin_type, int change2, int amount)
    {
        return coin_type = change2 / amount;
    }

