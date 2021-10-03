#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void solve(char **grid, int width, int height)
{
    int line_index = 0;
    char current_letter;

    for (int x = 0; x < width; ++x)
    {
        if (grid[0][x] != ' ')
        {
            current_letter = grid[0][x];
            line_index = x;
            int y;
            for (y = 1; grid[y][x] == '|'; ++y)
            {
                if (x != width && (grid[y][x + 1] == '-'))
                    x += 3;
                else if (x != width && (grid[y][x - 1] == '-'))
                    x -= 3;
            }
            printf("%c%c\n", current_letter, grid[y][x]);
            x = line_index + 1;
        }
    }
}

int main(void)
{
    int W;
    int H;
    char **grid;

    scanf("%d%d", &W, &H);
    fgetc(stdin);

    grid = (char **)malloc(sizeof(char *) * H);
    for (int i = 0; i < H; ++i)
        grid[i] = (char *)malloc(sizeof(char) * W);

    for (int i = 0; i < H; i++)
    {
        char line[1025];
        scanf("%[^\n]", line);
        fgetc(stdin);
        strcpy(grid[i], line);
    }

    solve(grid, W, H);

    for (int i = 0; i < H; i++)
        free(grid[i]);
    free(grid);

    return (0);
}