#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

pair<int, int> get_new_position(int x, int y, pair<int, int> dir, int t1, int t2, int t3)
{
    double new_x, new_y;

    new_x = x + dir.first * ((t3 - t1) / static_cast<double>(t2 - t1));
    new_y = y + dir.second * ((t3 - t1) / static_cast<double>(t2 - t1));
    return (make_pair(floor(new_x), floor(new_y)));
}

pair<int, int> get_asteroid_direction(vector<string> grid, char letter, int x, int y, bool *found)
{
    pair<int, int> dir(0.0, 0.0);

    for (int new_y = 0; new_y < grid.size(); ++new_y)
    {
        for (int new_x = 0; new_x < grid[0].length(); ++new_x)
        {
            if (grid[new_y][new_x] == letter)
            {
                int max;

                dir.first = new_x - x;
                dir.second = new_y - y;

                *found = true;
                break;
            }
        }
    }
    return (dir);
}

int main(void)
{
    int W;
    int H;
    int T1;
    int T2;
    int T3;

    cin >> W >> H >> T1 >> T2 >> T3;
    cin.ignore();

    vector<string> grid1;
    vector<string> grid2;
    vector<string> output;
    for (int i = 0; i < H; i++)
    {
        string firstPictureRow;
        string secondPictureRow;

        cin >> firstPictureRow >> secondPictureRow;
        cin.ignore();

        output.push_back(string(W, '.'));
        grid1.push_back(firstPictureRow);
        grid2.push_back(secondPictureRow);
        grid1[i][W] = '\0';
    }

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (grid1[y][x] != '.')
            {
                bool found = false;
                char letter = grid1[y][x];

                pair<int, int> dir = get_asteroid_direction(grid2, letter, x, y, &found);
                if (found)
                {
                    pair<int, int> pos = get_new_position(x, y, dir, T1, T2, T3);
                    if (pos.first >= 0 && pos.second >= 0 && pos.first < W && pos.second < H)
                    {
                        if (output[pos.second][pos.first] == '.')
                            output[pos.second][pos.first] = letter;
                        if (output[pos.second][pos.first] != '.' && letter < output[pos.second][pos.first])
                            output[pos.second][pos.first] = letter;
                    }
                }
            }
        }
    }
    for (int i = 0; i < H; ++i)
        cout << output[i] << endl;

    return (0);
}