#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    typedef vector<pair<char, int>> names;
    names name;
    for (int i = 0; i < 26; i++)
    {
        name.push_back(make_pair(i + 'A', 0));
    }

    int times = 0;
    cin >> times;
    string str;
    getline(cin, str);

    while (times--)
    {

        getline(cin, str);
        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] >= 'a' && str[i] <= 'z')
            {
                // str[i] +=  'A' - 'a';
                str[i] = str[i] + 'A' - 'a';
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                name[str[i] - 'A'].second++;
            }
        }
    }
    sort(name.begin(), name.end(), cmp);

    for (auto i : name)
    {
        if (i.second != 0)
        {
            cout << i.first << ' ' << i.second << endl;
        }
    }
}