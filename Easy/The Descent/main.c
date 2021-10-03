#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{

    // game loop
    while (1)
    {
        int mountain_h = 0, highest_mountain = 0, mountain_index = 0;
        for (int i = 0; i < 8; i++)
        {
            // represents the height of one mountain.
            scanf("%d", &mountain_h);
            if (mountain_h > highest_mountain)
            {
                mountain_index = i;
                highest_mountain = mountain_h;
            }
        }

        printf("%d\n", mountain_index); // The index of the mountain to fire on.
    }

    return (0);
}