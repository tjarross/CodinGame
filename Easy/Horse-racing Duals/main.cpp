#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    vector<int> power;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        int Pi;
        cin >> Pi;
        cin.ignore();
        power.push_back(Pi);
    }

    sort(power.begin(), power.end());

    int closest_power = 10000000;
    for (int i = 0; i < power.size() - 1; ++i)
    {
        if ((power[i + 1] - power[i]) < closest_power)
            closest_power = (power[i + 1] - power[i]);
    }

    cout << closest_power << endl;

    return (0);
}