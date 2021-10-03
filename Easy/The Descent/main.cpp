#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    // game loop
    while (1)
    {
        int highestMountain = 0, mountainIndex = 0;
        for (int i = 0; i < 8; i++)
        {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH;
            cin.ignore();
            cerr << mountainH << endl;
            if (mountainH > highestMountain)
            {
                mountainIndex = i;
                highestMountain = mountainH;
            }
        }

        cout << mountainIndex << endl; // The index of the mountain to fire on.
    }
    return (0);
}