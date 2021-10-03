#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int cmpfn(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int *power;
    int N;
    scanf("%d", &N);

    power = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        int pi;
        scanf("%d", &pi);
        power[i] = pi;
    }

    qsort(power, N, sizeof(int), cmpfn);

    int closest_power = 10000000;
    for (int i = 0; i < N - 1; ++i)
    {
        if ((power[i + 1] - power[i]) < closest_power)
            closest_power = (power[i + 1] - power[i]);
    }
    printf("%d\n", closest_power);

    free(power);

    return (0);
}