#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int loss = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = i + 1;
        for (; j < n && v[j] < v[i]; ++j)
        {
            if (v[i] - v[j] > loss)
                loss = v[i] - v[j];
            if (v[j] > v[i])
            {
                i = j;
                break;
            }
        }
        if (j == n)
            break;
    }

    printf("%d\n", -loss);

    return 0;
}