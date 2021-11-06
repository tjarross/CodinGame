#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);

    if (N == 1)
        printf("1\n");
    else
        printf("%d\n", (int)pow(N, 3) - (int)pow(N - 2, 3));

    return 0;
}