#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    typedef vector<pair<char, int>> dict;
    dict vp;
    for (int i = 0; i < 26; i++)
    {
        vp.push_back(make_pair(i + 'A', 0));
    }
    int time = 0;
    cin >> time;
    string s;
    getline(cin, s);
    while (time--)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] += 'A' - 'a';
            }
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                vp[s[i] - 'A'].second++;
            }
        }
    }

    sort(vp.begin(), vp.end(), cmp);
    for (auto i : vp)
    {
        if (i.second != 0)
        {
            cout << i.first << ' ' << i.second << endl;
        }
    }
}

// 使用兩個 array
// 一個存字母出現次數 a[]
// 一個存字母順序 b[]
// 用出現字母次數做 bubble sort 的 swap 時 ， 同時做字母順序的 swap

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int a[26] = {0};
//     int b[26] = {0};
//     for (int i = 0; i < 26; i++)
//     {
//         b[i] = i;
//     }
//     int time;
//     string s;
//     cin >> time;
//     // clear buffer (\n)
//     // getline會直接吃到N輸入中的換行符號'\n'
//     getline(cin, s);
//     while (time--)
//     {
//         getline(cin, s);
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] >= 'a' && s[i] <= 'z')
//             {
//                 s[i] += 'A' - 'a';
//             }
//             if (s[i] >= 'A' && s[i] <= 'Z')
//             {
//                 a[s[i] - 'A']++;
//             }
//         }
//     }
//     for (int i = 0; i < 26 - 1; i++)
//     {
//         for (int j = 0; j < 26 - i - 1; j++)
//         {
//             if (a[j] < a[j + 1])
//             {
//                 swap(a[j], a[j + 1]);
//                 swap(b[j], b[j + 1]);
//             }
//         }
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (a[i] != 0)
//         {
//             cout << char(b[i] + 'A') << ' ' << a[i] << endl;
//         }
//     }
// }
