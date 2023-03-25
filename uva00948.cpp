#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> feb;
    feb.push_back(1);
    feb.push_back(2);
    for (int i = 2; i < 40; i++)
    {
        feb.push_back(feb[i - 1] + feb[i - 2]);
    }

    reverse(feb.begin(), feb.end());
    int times;
    cin >> times;
    while (times--)
    {

        int num;
        vector<int> ans;
        cin >> num;
        int num_copy = num;
        int i = 0;
        while (feb[i] > num)
            i++;
        for (; i < feb.size(); i++)
        {
            if (num >= feb[i])
            {
                num -= feb[i];
                ans.push_back(1);
                // i++;
                // if (i < feb.size())
                //     ans.push_back(0);
            }
            else
            {
                ans.push_back(0);
            }
        }
        cout << num_copy << " = ";
        for (auto j : ans)
            cout << j;
        cout << " (fib)\n";
    }
}
