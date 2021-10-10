#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int check_little_square(char sudoku[9][9], int x, int y, char c)
{
    int i;
    int j;
    int cpt;

    i = -1;
    cpt = 0;
    while (++i < 3)
    {
        j = -1;
        while (++j < 3)
        {
            if (sudoku[y + i][x + j] == c)
                ++cpt;
        }
    }
    return ((cpt > 1) ? (1) : (0));
}

int check_square_by_square(char sudoku[9][9], char c)
{
    int i;
    int j;

    i = -1;
    while (++i < 3)
    {
        j = -1;
        while (++j < 3)
        {
            if (check_little_square(sudoku, j * 3, i * 3, c))
                return (1);
        }
    }
    return (0);
}

int check_lines_columns(char sudoku[9][9], char c)
{
    int cx;
    int cy;
    for (int y = 0; y < 9; ++y)
    {
        cx = 0;
        cy = 0;
        for (int x = 0; x < 9; ++x)
        {
            if (sudoku[y][x] == c)
                cx++;
            if (sudoku[x][y] == c)
                cy++;
        }
        if (cx > 1 || cy > 1)
            return (1);
    }
    return (0);
}

int check_characters(char sudoku[9][9])
{
    int i;
    int j;

    i = -1;
    while (++i < 9)
    {
        j = -1;
        while (++j < 9)
        {
            if (sudoku[i][j] != '.' && !isdigit(sudoku[i][j]))
                return (1);
        }
    }
    return (0);
}

int check_validity(char sudoku[9][9])
{
    int err;
    int i;
    int cpt;

    err = 0;
    i = '0';
    cpt = 0;
    err += check_characters(sudoku);
    while (++i <= '9')
    {
        err += check_lines_columns(sudoku, i);
        err += check_square_by_square(sudoku, i);
    }
    return (err);
}

int main()
{
    char sudoku[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int n;
            scanf("%d", &n);
            sudoku[i][j] = '0' + n;
        }
    }

    printf("%s\n", check_validity(sudoku) ? "false" : "true");

    return 0;
}