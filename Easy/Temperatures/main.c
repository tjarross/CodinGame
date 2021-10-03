#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);
    int closestTemp = 5526;

    for (int i = 0; i < n; i++)
    {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);
        if (abs(t) <= abs(closestTemp))
        {
            if (-t == closestTemp)
                closestTemp = abs(t);
            else
                closestTemp = t;
        }
    }

    if (n)
        printf("%d\n", closestTemp);
    else
        printf("0\n");

    return (0);
}