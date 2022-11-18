#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    int x_max, y_max;
    cin >> x_max >> y_max;

    int coordinate[50][50] = {0};

    // N,E,S,W
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    map<char, int> map1;
    map1['N'] = 0;
    map1['E'] = 1;
    map1['S'] = 2;
    map1['W'] = 3;

    map<int, char> map2;
    map2[0] = 'N';
    map2[1] = 'E';
    map2[2] = 'S';
    map2[3] = 'W';

    int x_start, y_start;
    char f_start;
    string s;

    while (cin >> x_start >> y_start >> f_start >> s)
    {
        int face = map1[f_start];
        int dest_x = x_start;
        int dest_y = y_start;
        bool fall = false;

        for (long long unsigned int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'F')
            {
                dest_x += dx[face];
                dest_y += dy[face];
                if (dest_x > x_max || dest_y > y_max || dest_x < 0 || dest_y < 0)
                {

                    dest_x = dest_x - dx[face];
                    dest_y = dest_y - dy[face];

                    if (coordinate[dest_x][dest_y] == 0)
                    {
                        coordinate[dest_x][dest_y] = 1;
                        fall = true;
                        break;
                    }
                }
            }
            else
            {
                if (s[i] == 'R')
                {
                    face = (face + 1) % 4;
                }
                else
                {
                    face = (face - 1 + 4) % 4;
                }
            }
        }

        if (fall)
        {
            cout << dest_x << ' ' << dest_y << ' ' << map2[face] << ' ' << "LOST" << endl;
        }
        else
        {
            cout << dest_x << ' ' << dest_y << ' ' << map2[face] << endl;
        }
    }
}
