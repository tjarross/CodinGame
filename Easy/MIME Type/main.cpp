#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

int main(void)
{
    map<string, string> ext_mt;
    map<string, string>::iterator it;

    int N; // Number of elements which make up the association table.
    cin >> N;
    cin.ignore();

    int Q; // Number Q of file names to be analyzed.
    cin >> Q;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string EXT; // file extension
        string MT;  // MIME type.
        cin >> EXT >> MT;
        cin.ignore();

        transform(EXT.begin(), EXT.end(), EXT.begin(),
                  [](unsigned char c)
                  { return tolower(c); });
        ext_mt[EXT] = MT;
    }
    for (int i = 0; i < Q; i++)
    {
        string FNAME;
        getline(cin, FNAME); // One file name per line.
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(),
                  [](unsigned char c)
                  { return tolower(c); });

        if (FNAME.find(".") == string::npos)
        {
            cout << "UNKNOWN" << endl;
            continue;
        }

        it = ext_mt.find(FNAME.substr(FNAME.find_last_of('.') + 1));
        if (it != ext_mt.end())
            cout << it->second << endl;
        else
            cout << "UNKNOWN" << endl;
    }
    return (0);
}