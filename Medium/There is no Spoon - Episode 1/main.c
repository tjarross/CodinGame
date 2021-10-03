#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    // the number of cells on the X axis
    int width;
    scanf("%d", &width);

    // the number of cells on the Y axis
    int height;
    scanf("%d", &height);
    fgetc(stdin);

    char grid[height][width + 1];
    int positions[4];

    for (int i = 0; i < height; i++)
    {
        // width characters, each either 0 or .
        char line[32];
        scanf("%[^\n]", line);
        fgetc(stdin);
        strcpy(grid[i], line);
        grid[i][width] = '\0';
    }

    for (int i = 0; i < height; ++i) // Height
    {
        for (int j = 0; j < width; ++j) // Width
        {
            if (grid[i][j] == '0')
            {
                int found = 0;
                char *index;

                if (j + 1 < width && (index = strchr(&grid[i][j + 1], '0')) != NULL)
                {
                    positions[0] = index - grid[i];
                    positions[1] = i;
                }
                else
                {
                    positions[0] = -1;
                    positions[1] = -1;
                }

                found = 0;
                for (int k = i; k < height; ++k)
                {
                    if (grid[k + 1][j] == '0')
                    {
                        positions[2] = j;
                        positions[3] = k + 1;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    positions[2] = -1;
                    positions[3] = -1;
                }
                printf("%d %d %d %d %d %d\n", j, i, positions[0], positions[1], positions[2], positions[3]);
            }
        }
    }

    return (0);
}