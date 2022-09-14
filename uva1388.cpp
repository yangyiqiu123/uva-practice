#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    // 原本雕塑
    int n;
    // 新的雕塑
    int m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        double ans = 0.0;
        for (int i = 1.0; i < n; i++)
        {
            // 原本雕塑其中一根舍為原點
            // a 為在總長為 m+n 的距離中每根原本雕塑的位置
            double a = (double)i/n*(m+n);

            // fabs() 取小數點的絕對值
            // floor(a + 0.5) 四捨五入 ， 即最後每根雕塑的終點位置
            // fabs(a - floor(a + 0.5)) 為與原本雕塑的位置離最近的終點位置的距離差
            // 再除以(m+n)求比例

            // 不可能有兩根原本雕塑要佔同一個終點位置
            // 如果兩個原本雕塑要佔同一終點位置，其四捨五入後結果要相同
            // 如 0.5 與 1.4999999 其距離 < 1
            // 但這是不可能的 因為加入新雕塑後距離等於 1
            // 原本雕塑更少，距離應該要更大
            ans += fabs(a - floor(a + 0.5))/(m+n);
        }
        // 乘上總長 10000
        printf("%.4lf\n", ans*10000);
    }
}
