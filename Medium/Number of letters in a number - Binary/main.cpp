#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline int get_bit_id(long long n, int bit_index)
{
    return (n & (long long)(pow(2, bit_index))) >> bit_index;
}

int main(void)
{
    long long start;
    long long n;
    cin >> start >> n;
    cin.ignore();

    long long next;
    while (n--)
    {
        // Skipping useless zeroes
        int j = log2(start);

        next = 0;
        for (; j >= 0; --j)
            next += 4 - get_bit_id(start, j);

        if (start == next)
            break;

        start = next;
    }

    cout << start << endl;

    return (0);
}