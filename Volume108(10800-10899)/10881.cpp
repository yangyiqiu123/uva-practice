#include <cstdio>
#include <algorithm>
using namespace std;

// 螞蟻相互碰到就往反方向走
// 不考慮螞蟻個體差異的話，能看作對穿而過
// 所以 Before 直接加上 速度*時間 就會等於最終位置

// 考慮個體差異
// 把螞蟻從最小位置到最大位置作排序 其相對位置不變

// 但是輸入不一定是從最小位置開使輸入
// 所以要 order 序列記住第i隻輸入的螞蟻在哪個位置上

struct Ant
{
    // 第幾隻輸入的
    int id;

    // position
    int p;

    // diration
    int d;
};
Ant Before[10000];
Ant After[10000];

const char dirname[][100] = {"L", "Turing", "R"};

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        int L, T, n;
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            char c;
            scanf("%d %c", &a, &c);
            b = (c == 'L' ? -1 : 1);
            Before[i] = {i, a, b};
            After[i] = {0, a + T * b, b};
        }

        int order[10000];
        sort(Before, Before + n, [](Ant a, Ant b)
             { return a.p < b.p; });
        for (int i = 0; i < n; i++)
        {
            // 輸入的第i隻螞蟻是終型態中order[i]隻螞蟻
            // 編號 i 在第幾個位置上

            // 設 i 為 0
            // Before[i].id 是在最終序列中第1個是第幾隻輸入的螞蟻
            // 如 Before[0].id 為 3
            // order[0] 為第一隻輸入的螞蟻
            // order[1] 為第二隻輸入的螞蟻
            // order[Before[0].id] = order[3] 為第4隻輸入的螞蟻

            // = i 表示在最終序列的第幾個位置上

            // 第4隻輸入的螞蟻，最終序列的第0個位置上
            order[Before[i].id] = i;
        }

        sort(After, After + n, [](Ant a, Ant b)
             { return a.p < b.p; });
        for (int i = 0; i < n; i++)
        {
            if (After[i].p == After[i + 1].p)
            {
                After[i].d = After[i + 1].d = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int a = order[i];
            if (After[a].p < 0 || After[a].p > L)
            {
                printf("Fell off");
            }
            else
            {
                printf("%d %s", After[a].p, dirname[After[a].d + 1]);
            }
        }
        printf("\n");
    }
}



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Ant
{
    // 位置
    int pos;
    // 方向
    char dir;
    // 輸入順序
    int order;
    // 在哪個最終位置
    int b;
};

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        vector<Ant> ant;

        int L, T, n;
        scanf("%d %d %d", &L, &T, &n);
        for (int i = 0; i < n; i++)
        {
            int a;
            char b;
            scanf("%d %c", &a, &b);
            ant.push_back({a, b, i, 0});
        }

        // 先排序一次，並確認最終順序
        // 宜東前後相對位置不變
        sort(ant.begin(), ant.end(), [](Ant a, Ant b)
             { return a.pos < b.pos; });
        for (int i = 0; i < n; i++)
        {
            ant[i].b = i;
        }

        // 移動
        for (int i = 0; i < n; i++)
        {

            switch (ant[i].dir)
            {
            case 'R':
                ant[i].pos += T;
                break;
            case 'L':
                ant[i].pos -= T;
                break;
            default:
                break;
            }
            if (ant[i].pos < 0 || ant[i].pos > L)
            {
                ant[i].dir = 'F';
            }
        }

        // 移動完再排一次
        sort(ant.begin(), ant.end(), [](Ant a, Ant b)
             { return a.pos < b.pos; });

        // 不需要因為已經排好序了
        // 只要寫
        // for (int i = 0; i < n; i++)
        // {
        //     if (ant[i].pos == ant[i + 1].pos)
        //     {
        //         ant[i].dir = ant[i + 1].dir = 'T';
        //     }
        // }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ant[i].pos == ant[j].pos)
                {
                    ant[i].dir = 'T';
                    ant[j].dir = 'T';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ant[j].order == i)
                {
                    if (ant[j].dir == 'F')
                    {
                        printf("FELL off\n");
                    }
                    else if (ant[j].dir == 'T')
                    {
                        printf("Turning\n");
                    }
                    else
                    {
                        int g = ant[j].b;
                        printf("%d %c\n", ant[g].pos, ant[g].dir);
                    }
                }
            }
        }
    }
}
