#include <cs50.h>
#include <stdio.h>

int luhn_check(long n);
int get_length(long n);
string card_type(long n);

int main(void)
{
    long n;
    do
    {
        n = get_long("Please enter your credit card number:\n");
    }
    while (n < 0);
    if (luhn_check(n) == 1)
    {
        printf("%s\n", card_type(n));
    }
    else
    {
        printf("INVALID\n");
    }
}

string card_type(long n)
{
    int l = get_length(n);
    // 获取前两位数字
    long t = n;
    while (t > 99)
    {
        t /= 10;
    }
    // 获取第一位数字
    int f = t / 10;
    // 对不同信用卡号的分类
    if ((t == 34 || t == 37) && l == 15)
    {
        return "AMEX";
    }
    else if ((t == 51 || t == 52 || t == 53 || t == 54 || t == 55) && l == 16)
    {
        return "MASTERCARD";
    }
    else if (f == 4 && (l == 13 || l == 16))
    {
        return "VISA";
    }
    return "INVALID";
}

int luhn_check(long n)
{
    int l = get_length(n);
    int F = 0;
    int S = 0;
    // 同时处理两位数字,分别累加
    for (int i = 0; i < l; i += 2)
    {
        int f = n % 10;
        int s = (n / 10) % 10;
        s *= 2;
        F += f;
        S += (s % 10) + ((s / 10) % 10);
        n /= 100;
    }
    int L = (F + S) % 10;
    if (L == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_length(long n)
{
    int count = 0;
    do
    {
        n /= 10;
        count++;
    }
    while (n != 0);
    return count;
}
