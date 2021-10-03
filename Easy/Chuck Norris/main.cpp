#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int get_bit_id(int n, int bit_index)
{
    return (n & static_cast<int>(pow(2, bit_index))) >> bit_index;
}

int main(void)
{
    string MESSAGE;
    getline(cin, MESSAGE);

    int bit_id; // 1 or 0
    for (int i = 0; i < MESSAGE.length(); ++i)
    {
        int bit_index = 7; // Bit index in char
        while (bit_index)
        {
            bit_id = get_bit_id(MESSAGE[i], bit_index - 1);
            if (bit_id == 1)
                cout << "0 ";
            else if (bit_id == 0)
                cout << "00 ";

            while (get_bit_id(MESSAGE[i], bit_index - 1) == bit_id)
            {
                cout << "0";
                bit_index--;
                if (bit_index == 0)
                {
                    if (i + 1 == MESSAGE.length())
                        break;
                    ++i;
                    bit_index = 7;
                }
            }
            if (i < MESSAGE.length() && bit_index > 0)
                cout << " ";
        }
    }
    cout << endl;

    return (0);
}