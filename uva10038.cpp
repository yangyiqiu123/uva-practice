#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    

    int a;
    // cin>>a;
    while (cin>>a)
    {

        vector<int> count;
        vector<int> num;
        for (int i = 0; i < a ; i++)
        {
            
            int b;
            cin >> b;
            num.push_back(b);
        }

        int f = 0;
        for(int i=0;i<a-1;i++){
            count.push_back(0);
        }
        for (int i = 0; i < a - 1; i++)
        {
            int b = abs(num[i] - num[i + 1]);

            if (b > a-1||b<1)
            {
                f = 1;
                break;
            }
            else
            {
                count[b - 1] += 1;
            }
        }
        for (int i = 0; i < a-1; i++)
        {
            if (count[i] != 1)
            {
                f = 1;
                break;
            }
        }

        if (f == 0)
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not jolly" << endl;
        }
    }
}