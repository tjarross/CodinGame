#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void decode(string message, int start, vector<string> rotors)
{
    for (int i = 0; i < message.length(); ++i)
    {
        message[i] = 'A' + rotors[2].find(message[i]);
        message[i] = 'A' + rotors[1].find(message[i]);
        message[i] = 'A' + rotors[0].find(message[i]);
        message[i] = (message[i] - 'A') - start - i;
        if (message[i] < 0)
            message[i] = 26 - (abs(message[i]) % 26);
        message[i] += 'A';
        if (message[i] == '[')
            message[i] = 'A';
    }
    cout << message << endl;
}

void encode(string message, int start, vector<string> rotors)
{
    for (int i = 0; i < message.length(); ++i)
    {
        message[i] = 'A' + ((message[i] - 'A' + start + i) % 26);
        message[i] = rotors[0][message[i] - 'A'];
        message[i] = rotors[1][message[i] - 'A'];
        message[i] = rotors[2][message[i] - 'A'];
    }
    cout << message << endl;
}

int main(void)
{
    vector<string> rotors;

    string Operation;
    getline(cin, Operation);

    int pseudoRandomNumber;
    cin >> pseudoRandomNumber;
    cin.ignore();

    for (int i = 0; i < 3; i++)
    {
        string rotor;
        getline(cin, rotor);
        rotors.push_back(rotor);
    }
    string message;
    getline(cin, message);

    if (Operation == "ENCODE")
        encode(message, pseudoRandomNumber, rotors);
    else
        decode(message, pseudoRandomNumber, rotors);

    return (0);
}