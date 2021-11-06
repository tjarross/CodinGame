#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);

    char t[N][10];
    int smallest = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", t[i]);
        if (strcmp(t[i], t[smallest]) < 0)
            smallest = i;
    }

    printf("%s\n", t[smallest]);

    return 0;
}