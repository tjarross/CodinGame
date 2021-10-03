#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    // the X position of the light of power
    int lightX;
    // the Y position of the light of power
    int lightY;
    // Thor's starting X position
    int initialTX;
    // Thor's starting Y position
    int initialTY;
    scanf("%d%d%d%d", &lightX, &lightY, &initialTX, &initialTY);

    // game loop
    while (1)
    {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);
        if (initialTX < lightX)
        {
            if (initialTY < lightY)
            {
                initialTY++;
                printf("SE\n");
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                printf("NW\n");
            }
            else
            {
                initialTX++;
                printf("E\n");
            }
        }
        else if (initialTX > lightX)
        {
            if (initialTY < lightY)
            {
                initialTY++;
                printf("SW\n");
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                printf("NE\n");
            }
            else
            {
                initialTX--;
                printf("W\n");
            }
        }
        else
        {
            if (initialTY < lightY)
            {
                initialTY++;
                printf("S\n");
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                printf("N\n");
            }
        }
    }

    return (0);
}