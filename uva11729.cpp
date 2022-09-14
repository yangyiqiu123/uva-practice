#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Job
{
    // 交代時間
    int b;

    // 執行時間
    int j;

    // 用 overloading 的寫法，做 Struct 的降序排列
    // bool operator>(const Job &x) const
    // {
    //     因為預設是升序，要寫相反
    //     return j < x.j;
    // }
};
int main()
{

    //部下
    int n;

    // 交代時間
    int b;

    // 執行時間
    int j;

    // 第幾個 case
    int num = 1;

    while (scanf("%d", &n) == 1 && n)
    {
        vector<Job> v;

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &b, &j);
            v.push_back({b, j});
        }

        // 用 lambda 的寫法做降序
        sort(v.begin(), v.end(), [](Job a, Job b)
             { return a.j > b.j; });

        // 用 overloading 的寫法，做 Struct 的降序排列
        // sort(v.begin(), v.end());

        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp = tmp + v[i].b;
            ans = max(ans, tmp + v[i].j);
        }
        printf("%d : %d", num++, ans);
    }
}
