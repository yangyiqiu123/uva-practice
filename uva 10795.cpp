#include <iostream>
#include <cstdio>
using namespace std;

// 假設要移動盤子 k 
// 比 k 大的盤子不需要移動，也不會礙事。可以看做不存在
// 要把 k 移動到目標柱子上
// 這時比 k 小的盤子不能再 k 在的柱子上，也不能在目標柱子上
// 因此只能在中轉柱子上
// 這時 k 在的柱子上只有 k，目標柱子為空，中轉柱子有1,2,3 ... k-1
// 把這個局面稱為參考局面

// 盤子的移動是可逆的
// 只要求出初始局面移動至參考局面 + 最終局面移動至參考局面 + 1(移動盤子k)，就是答案


// 起始狀態
int start[60];

// 最終狀態
int final[60];

long long ans = 0;

// f(初始狀態,要移動的盤子i,盤子i要移到哪根柱子)
// 把盤子全部移到 fin 的步數
long long f(int *p, int i, int fin)
{

    // 移完了
    if (i == 0)
    {
        return 0;
    }

    // 如果要移動的盤子 i 已經在他最後要去的位置
    // 移他上面的 i-1 號盤子 
    if (p[i] == fin)
    {
        return f(p, i - 1, fin);
    }

    // 當p[i]不等於fin時
    // 先把 1,2,3 ... ,i-1 個盤子移到中轉的柱子
    // 柱子的編號為1,2,3 所以中轉的柱子編號為 6-起始的柱子-目標的柱子
    // 最後把 i-1 個盤子從中轉的柱子移到目標柱子
    // 根據經典盒內塔問題這個步驟需要2^(i-1)次
    // 並沒有把第i根柱子的移動算進去
    return f(p, i - 1, 6 - p[i] - fin) + (1LL << (i - 1));
}

int main()
{
    int n;

    while (scanf("%d", &n) == 1 && n)
    {

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &start[i]);
        }
        for (int i = 1; i <=n; i++)
        {
            scanf("%d", &final[i]);
        }
        int k = n;
        while (k >= 1 && start[k] == final[k])
        {
            k--;
        }
        ans=0;
        if (k>=1)
        {
            int other=6 - start[k] - final[k];

        // 只要求出初始局面移動至參考局面 + 最終局面移動至參考局面 + 1(移動盤子k)，就是答案
            ans = f(start, k - 1,other ) + f(final, k - 1, other) + 1;
        }
        printf("%lld\n", ans);
    }
}

