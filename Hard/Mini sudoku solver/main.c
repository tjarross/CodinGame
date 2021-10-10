#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int find_unassigned(char sudoku[4][5], int *row, int *col)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            if (sudoku[i][j] == '0')
            {
                *row = i;
                *col = j;
                return (1);
            }
        }
    }
    return (0);
}

int check_for_chars(char sudoku[4][5], int row, int col, char c)
{
    int i;
    int j;
    int err;

    i = -1;
    err = 0;
    while (++i < 4)
    {
        j = -1;
        if (i < 2)
            while (++j < 2)
            {
                if (sudoku[row - row % 2 + i][col - col % 2 + j] == c)
                    return (0);
            }
        if (sudoku[row][i] == c)
            return (0);
        if (sudoku[i][col] == c)
            return (0);
    }
    return (1);
}

int fill_sudoku(char sudoku[4][5])
{
    int row;
    int col;
    char i;

    i = '0';
    if (!find_unassigned(sudoku, &row, &col))
        return (1);
    while (++i <= '4')
    {
        if (check_for_chars(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            if (fill_sudoku(sudoku))
                return (1);
            sudoku[row][col] = '0';
        }
    }
    return (0);
}

int main()
{
    char sudoku[4][5];
    scanf("%s", sudoku[0]);
    scanf("%s", sudoku[1]);
    scanf("%s", sudoku[2]);
    scanf("%s", sudoku[3]);

    fill_sudoku(sudoku);

    for (int i = 0; i < 4; ++i)
        printf("%.*s\n", 4, sudoku[i]);

    return 0;
}