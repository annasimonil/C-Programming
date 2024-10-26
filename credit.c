#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool luhn_algorithm(long number);
void check_card_type(long number);

int main(void)
{
    long n = get_long("Number: ");

    if (luhn_algorithm(n))
    {
        check_card_type(n);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhn_algorithm(long number)
{
    int sum = 0;
    bool multiply = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (multiply)
        {
            digit *= 2;
            sum += (digit / 10) + (digit % 10);
        }
        else
        {
            sum += digit;
        }

        multiply = !multiply;
        number /= 10;
    }

    return (sum % 10) == 0;
}

void check_card_type(long number)
{
    int length = 0;
    long start_digit = number;
    while (start_digit >= 100)
    {
        start_digit /= 10;
        length++;
    }
    length += 2;

    if ((start_digit == 34 || start_digit == 37) && (length == 15))
    {
        printf("AMEX\n");
    }

    else if ((start_digit >= 51 && start_digit <= 55) && (length == 16))
    {
        printf("MASTERCARD\n");
    }

    else if ((start_digit / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
