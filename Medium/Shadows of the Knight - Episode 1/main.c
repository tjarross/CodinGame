#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);

    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);

    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);

    int xmin = 0, ymin = 0, xmax = W, ymax = H;
    // game loop
    while (1)
    {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4];
        scanf("%s", bomb_dir);

        if (strcmp(bomb_dir, "U") == 0)
        {
            ymax = Y0 - 1;
            Y0 = (ymax + ymin) / 2;
        }
        else if (strcmp(bomb_dir, "UR") == 0)
        {
            xmin = X0 + 1;
            ymax = Y0 - 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (strcmp(bomb_dir, "R") == 0)
        {
            xmin = X0 + 1;
            X0 = (xmax + xmin) / 2;
        }
        else if (strcmp(bomb_dir, "DR") == 0)
        {
            xmin = X0 + 1;
            ymin = Y0 + 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (strcmp(bomb_dir, "D") == 0)
        {
            ymin = Y0 + 1;
            Y0 = (ymax + ymin) / 2;
        }
        else if (strcmp(bomb_dir, "DL") == 0)
        {
            xmax = X0 - 1;
            ymin = Y0 + 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (strcmp(bomb_dir, "L") == 0)
        {
            xmax = X0 - 1;
            X0 = (xmax + xmin) / 2;
        }
        else if (strcmp(bomb_dir, "UL") == 0)
        {
            xmax = X0 - 1;
            ymax = Y0 - 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }

        // the location of the next window Batman should jump to.
        printf("%d %d\n", X0, Y0);
    }
    return (0);
}