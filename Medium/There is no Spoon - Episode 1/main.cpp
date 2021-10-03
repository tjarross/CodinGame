#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <array>

using namespace std;

int main(void)
{
    int width; // the number of cells on the X axis
    cin >> width;
    cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height;
    cin.ignore();

    char grid[height][width + 1];
    array<int, 4> positions;

    for (int i = 0; i < height; i++)
    {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        strcpy(grid[i], line.c_str());
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

                if (j + 1 < width && (index = strchr(&grid[i][j + 1], '0')) != nullptr)
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
                cout << j << " " << i << " " << positions[0] << " " << positions[1] << " " << positions[2] << " " << positions[3] << endl;
            }
        }
    }
    return (0);
}