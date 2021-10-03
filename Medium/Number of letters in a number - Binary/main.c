#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int get_bit_id(long long n, int bit_index)
{
    return (n & (long long)(pow(2, bit_index))) >> bit_index;
}

int main(void)
{
    long long start;
    long long n;
    scanf("%lld%lld", &start, &n);

    long long next;
    while (n--)
    {
        // Skipping useless zeroes
        int j = log2(start);

        next = 0;
        for (; j >= 0; --j)
            next += 4 - get_bit_id(start, j);

        if (start == next)
            break;

        start = next;
    }

    printf("%lld\n", start);

    return (0);
}