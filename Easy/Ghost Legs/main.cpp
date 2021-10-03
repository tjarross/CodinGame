#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<string> grid)
{
    int line_index = 0;
    char current_letter;

    for (int x = 0; x < grid[0].length(); ++x)
    {
        if (grid[0][x] != ' ')
        {
            current_letter = grid[0][x];
            line_index = x;
            int y;
            for (y = 1; grid[y][x] == '|'; ++y)
            {
                if (x != grid[0].length() && (grid[y][x + 1] == '-'))
                    x += 3;
                else if (x != grid[0].length() && (grid[y][x - 1] == '-'))
                    x -= 3;
            }
            cout << current_letter << grid[y][x] << endl;
            x = line_index + 1;
        }
    }
}

int main(void)
{
    int W;
    int H;
    vector<string> grid;

    cin >> W >> H;
    cin.ignore();
    for (int i = 0; i < H; i++)
    {
        string line;
        getline(cin, line);
        grid.push_back(line);
    }
    solve(grid);

    return (0);
}