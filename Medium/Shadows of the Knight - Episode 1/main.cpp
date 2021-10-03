#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H;
    cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N;
    cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0;
    cin.ignore();

    int xmin = 0, ymin = 0, xmax = W, ymax = H;
    // game loop
    while (1)
    {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir;
        cin.ignore();

        if (bombDir == "U")
        {
            ymax = Y0 - 1;
            Y0 = (ymax + ymin) / 2;
        }
        else if (bombDir == "UR")
        {
            xmin = X0 + 1;
            ymax = Y0 - 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (bombDir == "R")
        {
            xmin = X0 + 1;
            X0 = (xmax + xmin) / 2;
        }
        else if (bombDir == "DR")
        {
            xmin = X0 + 1;
            ymin = Y0 + 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (bombDir == "D")
        {
            ymin = Y0 + 1;
            Y0 = (ymax + ymin) / 2;
        }
        else if (bombDir == "DL")
        {
            xmax = X0 - 1;
            ymin = Y0 + 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        else if (bombDir == "L")
        {
            xmax = X0 - 1;
            X0 = (xmax + xmin) / 2;
        }
        else if (bombDir == "UL")
        {
            xmax = X0 - 1;
            ymax = Y0 - 1;
            X0 = (xmax + xmin) / 2;
            Y0 = (ymax + ymin) / 2;
        }
        cout << X0 << " " << Y0 << endl;
    }
    return (0);
}