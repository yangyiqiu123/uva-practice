// uva 11300

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;

// 原本持有的錢幣數
long long A[maxn];

// 設圓桌中任一人為第一個人
// 其原本持有的金幣數為 A[1]
// 他給最後一個人的錢為 x1
// 第二個人給他的錢為 x2
// 其最後擁有的錢幣數要為 avg
// 可寫成不等式 A[1] - x1 + x2 = avg
// 經過整理可得 x2 = x1 + avg - A[1]

// 同理
// A[2] - x2 + x3 = avg
// 整理可得 x3 = x2 + avg - A[2]
// x2 換掉得 x3 = x1 + avg - A[1] + avg - A[2]

// 在改寫成
// x1 = x1
// x2 = x1 - (A[1] - avg)
// x3 = x1 -(A[1] - avg + A[2] - avg)
// 其中設 B[0] = 0
// (A[1] - avg) 為 B[1]
// (A[1] - avg + A[2] - avg) 為 B[2]
// 可得
// x1 = x1
// x2 = x1 - B[1]
// x3 = x1 - B[2]

// 要求 x1 + x2 +...+ xn 的最小
// 等於
// |x1| + |x1 - B[1]| +...+ |x1 - B[n-1]|
// 要找 x1 到個各點距離的最小
// 要加絕對值是因為要求的是金幣轉移的數量
// 不管是正的(轉出)，或負的(轉入)都要算進去

// x1 在 B 的中位數 與 B 各點的距離會是最小值
long long B[maxn];
int sum;
int avg;
int main()
{
    int num;
    while (scanf("%d", &num) == 1 && num)
    {
        sum = 0;
        for (int i = 0; i < num; i++)
        {
            scanf("%lld", &A[i]);
            sum += A[i];
        }
        avg = sum / num;

        B[0] = 0;
        // 用疊代算出個各B的值
        // B[n] = B[n-1] + A[n] - avg
        for (int i = 1; i < num; i++)
        {
            B[i] = B[i - 1] + A[i] - avg;
        }

        // x1 在 B 的中位數 與 B 各點的距離會是最小值
        sort(B, B + num);
        int x1 = B[num / 2];

        int ans = 0;
        for (int i = 0; i < num; i++)
        {
            // |x1| + |x1 - B[1]| +...+ |x1 - B[n-1]|
            // 要找 x1 到個各點距離的最小
            // 要加絕對值是因為要求的是金幣轉移的數量
            // 不管是正的(轉出)，或負的(轉入)都要算進去
            ans += abs(x1 - B[i]);
        }
        printf("%d\n", ans);
    }
}
