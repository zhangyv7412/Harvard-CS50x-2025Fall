#include <stdio.h>
#include <cs50.h>

void num_legal(long n);
int luhn(long n);
int nth_last_digit(long n,int dight);
int get_first_two_digits(long n);
int get_length(long n);

int main(void)
{   long n;
    do
    {
        n = get_long("Please enter your credit card number:\n");
    }
    while(n < 0);
    int luhn_corr = luhn(n);
    if(luhn_corr == 1)
    {
        num_legal(n);
    }
    else
    {
        printf("INVALID\n");
    }
}

void num_legal(long n)
{
    int t = get_first_two_digits(n);
    int l = get_length(n);
    int s = t / 10;
    int f = t % 10;
    if ((t == 34 || t == 37) && l == 15)
    {
        printf("American Express\n");
    }
    else if((t == 51 || t == 52 || t == 53 || t == 54 || t == 55) && l == 16)
    {
        printf("MasterCard\n");
    }
    else if(f == 4 && (l == 13 || l == 16))
    {
        printf("Visa\n");
    }
}

int luhn(long n)
{
    long part1 = 0;
    long part2 = 0;
    while (true)
    {
        long digits = 10;
        part2 += nth_last_digit(n,1);
        n /= digits;
        if ((n % 10) > 9)
        {
            part1 += (nth_last_digit(n,1) + nth_last_digit(n,2));
        }
        else
        {
            part1 += nth_last_digit(n,1);
        }
        if ((n % 10) == 0)
        {
            break;
        }
    }
    int anw_value = part1 + part2;
    int luhn_corr;
    if (anw_value % 10 == 0)
    {
        luhn_corr = 1;
    }
    else
    {
        luhn_corr = 0;
    }
    return luhn_corr;
}

int nth_last_digit(long n, int digit)
{   digit = 1;
    for (int i = 0; i < digit; i++)
    {
        n /= 10;
    }
    int x = n % 10;
    return x;
}

int get_first_two_digits(long n)
{
    int first_digit;
    int second_digit;
    int length = 1;
    for(int i = 0;;i++)
    {   int third_last_digit = nth_last_digit(n,3);
        int second_last_digit = nth_last_digit(n,2);
        int first_last_digit = nth_last_digit(n,1);
        if(third_last_digit == 0 && second_last_digit != 0)
        {
                first_digit = second_last_digit;
                second_digit = first_last_digit;
                break;
        }
        length++;
        n /= 10;
    }
    return(first_digit * 10 + second_digit);
}

int get_length(long n)
{
    int first_digit;
    int second_digit;
    int length = 1;
    for(int i = 0;;i++)
    {
        int third_last_digit = nth_last_digit(n,3);
        int second_last_digit = nth_last_digit(n,2);
        int first_last_digit = nth_last_digit(n,1);
        if(third_last_digit == 0 && second_last_digit != 0)
        {
                break;
        }
        length++;
        n /= 10;
    }
    return(length);
}
