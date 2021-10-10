#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int roman_to_numeral(char *s)
{
    int n = 0;

    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'X')
            {
                n += 9;
                i++;
            }
            else if (s[i + 1] == 'V')
            {
                n += 4;
                i++;
            }
            else
                n += 1;
        }
        else if (s[i] == 'V')
            n += 5;
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                n += 40;
                i++;
            }
            else if (s[i + 1] == 'C')
            {
                n += 90;
                i++;
            }
            else
                n += 10;
        }
        else if (s[i] == 'L')
            n += 50;
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                n += 400;
                i++;
            }
            else if (s[i + 1] == 'M')
            {
                n += 900;
                i++;
            }
            else
                n += 100;
        }
        else if (s[i] == 'D')
            n += 500;
        else if (s[i] == 'M')
            n += 1000;
    }
    return n;
}

char *get_roman_digit(int n, int *sub)
{
    int digits[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char names[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;

    while (i < 13)
    {
        if (n >= digits[i])
        {
            *sub = digits[i];
            break;
        }
        i++;
    }
    return (strdup(names[i]));
}

void numeral_to_roman(char *s, int n)
{
    int sub = 0;
    char *digit;
    while (n)
    {
        digit = get_roman_digit(n, &sub);
        strcat(s, digit);
        n -= sub;
        free(digit);
    }
}

int main()
{
    char s[128] = {0};
    char rom_1[11];
    scanf("%s", rom_1);
    char rom_2[11];
    scanf("%s", rom_2);
    numeral_to_roman(s, roman_to_numeral(rom_1) + roman_to_numeral(rom_2));
    printf("%s\n", s);

    return 0;
}