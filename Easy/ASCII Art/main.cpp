#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int L;
    cin >> L;
    cin.ignore();

    int H;
    cin >> H;
    cin.ignore();

    string T;
    getline(cin, T);

    for (int i = 0; i < H; i++)
    {
        string ROW;
        getline(cin, ROW);

        for (int j = 0; j < T.length(); ++j)
        {
            if (!isalpha(T[j]))
                cout << ROW.substr(L * 26, L);
            else
                cout << ROW.substr(L * (toupper(T[j]) - 'A'), L);
        }
        cout << endl;
    }
    return (0);
}