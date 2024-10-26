#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cash;
    do
    {
        cash = get_int("Cash owned: ");
    }
    while (cash < 1);

    int counter = 0;

    int coins[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)

    {
        counter += cash / coins[i];  // Keeps track of number of coins
        cash %= coins[i];  // keeo tracks the ramaining cash after deduction of production of number of coins anf its value used
    }


    printf("%i\n", counter);

}
