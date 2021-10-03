#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

void tokenize(std::string const &str, const char *delim,
              std::vector<std::string> &out)
{
    char *token = strtok(const_cast<char *>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(std::string(token));
        token = strtok(nullptr, delim);
    }
}

int main(void)
{
    string s_LON;
    cin >> s_LON;
    cin.ignore();
    string s_LAT;
    cin >> s_LAT;
    cin.ignore();

    replace(s_LON.begin(), s_LON.end(), ',', '.');
    replace(s_LAT.begin(), s_LAT.end(), ',', '.');

    double LON = stod(s_LON);
    double LAT = stod(s_LAT);

    int N;
    cin >> N;
    cin.ignore();

    string closest;
    int closest_distance = -1;
    for (int i = 0; i < N; i++)
    {
        string DEFIB;
        getline(cin, DEFIB);

        std::vector<std::string> infos;
        tokenize(DEFIB, ";", infos);

        replace(infos[infos.size() - 2].begin(), infos[infos.size() - 2].end(), ',', '.');
        replace(infos[infos.size() - 1].begin(), infos[infos.size() - 1].end(), ',', '.');

        double d_lon = stod(infos[infos.size() - 2]);
        double d_lat = stod(infos[infos.size() - 1]);

        double x = (d_lon - LON) * cos((LAT + d_lat) / 2.f);
        double y = (d_lat - LAT);
        double d = sqrt(x * x + y * y) * 6371;

        if (closest_distance == -1)
        {
            closest_distance = d;
            closest = infos[1];
        }
        else if (d < closest_distance)
        {
            closest_distance = d;
            closest = infos[1];
        }
    }
    int first = closest.find(";");
    int last = closest.find(";", first + 1);
    cout << closest.substr(first + 1, last - first - 1) << endl;

    return (0);
}