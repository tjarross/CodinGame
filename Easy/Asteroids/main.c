#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void get_new_position(int pos[2], int x, int y, int *dir, int t1, int t2, int t3)
{
    pos[0] = floor(x + dir[0] * ((t3 - t1) / (double)(t2 - t1)));
    pos[1] = floor(y + dir[1] * ((t3 - t1) / (double)(t2 - t1)));
}

void get_asteroid_direction(int dir[2], char **grid, char letter, int x, int y, bool *found)
{
    dir[0] = 0;
    dir[1] = 0;

    for (int new_y = 0; grid[new_y] != NULL; ++new_y)
    {
        for (int new_x = 0; new_x < grid[new_y][new_x] != '\0'; ++new_x)
        {
            if (grid[new_y][new_x] == letter)
            {
                int max;

                dir[0] = new_x - x;
                dir[1] = new_y - y;

                *found = true;
                break;
            }
        }
    }
}

int main(void)
{
    int W;
    int H;
    int T1;
    int T2;
    int T3;

    char **grid1;
    char **grid2;
    char **output;

    scanf("%d%d%d%d%d", &W, &H, &T1, &T2, &T3);

    grid1 = (char **)malloc(sizeof(char *) * (H + 1));
    grid2 = (char **)malloc(sizeof(char *) * (H + 1));
    output = (char **)malloc(sizeof(char *) * (H + 1));
    for (int i = 0; i < H; i++)
    {
        char first_picture_row[W + 1];
        char second_picture_row[W + 1];
        scanf("%s%s", first_picture_row, second_picture_row);

        grid1[i] = (char *)malloc(sizeof(char) * (W + 1));
        grid2[i] = (char *)malloc(sizeof(char) * (W + 1));
        output[i] = (char *)malloc(sizeof(char) * (W + 1));

        strcpy(grid1[i], first_picture_row);
        strcpy(grid2[i], second_picture_row);
        memset(first_picture_row, '.', W);
        strncpy(output[i], first_picture_row, W);

        grid1[i][W] = '\0';
        grid2[i][W] = '\0';
        output[i][W] = '\0';
    }

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (grid1[y][x] != '.')
            {
                bool found = false;
                char letter = grid1[y][x];
                int dir[2];

                get_asteroid_direction(dir, grid2, letter, x, y, &found);
                if (found)
                {
                    int pos[2];
                    get_new_position(pos, x, y, dir, T1, T2, T3);
                    if (pos[0] >= 0 && pos[1] >= 0 && pos[0] < W && pos[1] < H)
                    {
                        if (output[pos[1]][pos[0]] == '.')
                            output[pos[1]][pos[0]] = letter;
                        if (output[pos[1]][pos[0]] != '.' && letter < output[pos[1]][pos[0]])
                            output[pos[1]][pos[0]] = letter;
                    }
                }
            }
        }
    }
    for (int i = 0; i < H; ++i)
        printf("%s\n", output[i]);

    for (int i = 0; i < H; ++i)
    {
        free(grid1[i]);
        free(grid2[i]);
        free(output[i]);
    }
    free(grid1);
    free(grid2);
    free(output);

    return (0);
}