#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n; // the number of temperatures to analyse
    cin >> n;
    cin.ignore();
    int closestTemp = 5526;
    for (int i = 0; i < n; i++)
    {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t;
        cin.ignore();
        if (abs(t) <= abs(closestTemp))
        {
            if (-t == closestTemp)
                closestTemp = abs(t);
            else
                closestTemp = t;
        }
    }

    if (n)
        cout << closestTemp << endl;
    else
        cout << 0 << endl;

    return (0);
}