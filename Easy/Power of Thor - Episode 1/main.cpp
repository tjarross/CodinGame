#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int lightX;    // the X position of the light of power
    int lightY;    // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY;
    cin.ignore();

    // game loop
    while (1)
    {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns;
        cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        if (initialTX < lightX)
        {
            if (initialTY < lightY)
            {
                initialTY++;
                cout << "SE" << endl;
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                cout << "NW" << endl;
            }
            else
            {
                initialTX++;
                cout << "E" << endl;
            }
        }
        else if (initialTX > lightX)
        {
            if (initialTY < lightY)
            {
                initialTY++;
                cout << "SW" << endl;
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                cout << "NE" << endl;
            }
            else
            {
                initialTX--;
                cout << "W" << endl;
            }
        }
        else
        {
            if (initialTY < lightY)
            {
                initialTY++;
                cout << "S" << endl;
            }
            else if (initialTY > lightY)
            {
                initialTY--;
                cout << "N" << endl;
            }
        }
    }
    return (0);
}