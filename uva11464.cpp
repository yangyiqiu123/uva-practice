#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <time.h> 
#include <windows.h>
using namespace std;

const int INF = 1000000; // 無限
const int maxn = 10000;
int n;
int A[maxn][maxn];
int temp[maxn][maxn];

DWORD star_time;
DWORD end_time;

int check(int s)
{
    // <cstring>
    // 設B的每個元素為0
    // 按位元進行附值
    // memset(a,1,sizeof(a)); // 這時候你去列印a的每一位，值都是16843009，而非你期望的1
    // 原因：int為四個位元組，這時候每個位元組被memset置為1，而每一個元素都是一個int，即 01 01 01 01，讀取十六進位制為 0x01010101，十進位制為 16843009
    // 對字元陣列初始化使用 memset 是很常見的用法
    
    // 47ms
    // star_time = GetTickCount();
    memset(temp, 0, sizeof(temp));
    // end_time = GetTickCount();

    // 或這樣寫
    // 265ms
	//  star_time = GetTickCount();
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            temp[i][j]=0;
        }


    }
    // end_time = GetTickCount();

    // 檢查進入函數的第一列是否可行
    for (int i = 0; i < n; i++)
    {
        // s & (1 << i) 依序檢查該位數是否是1
        // 如果是1的話能夠直接寫入temp，繼續推算第二row
        // 因為測資給的0能夠變成1，但1不能變成0
        if (s & (1 << i))
        {
            temp[0][i] = 1;
        }
        // 但當該位數為0，且測資為1時
        // 直接否定帶進函數的這個第一row的可能
        // 1不能變成0
        else if (A[0][i] == 1)
        {
            return INF;
        }

        // 如測資為
        // 010
        // 如帶進函數的這個第一row為
        // 011
        // 最後 temp 為 {0,1,1} ，並繼續推算第二row

        // 如測資為
        // 111
        // 如帶進函數的這個第一row為
        // 011
        // 直接否定這一可能

    }

    // 用第一row 推第二row
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            // 加上 上下左右
            int sum = 0;
            if (r > 0)
            {
                sum += temp[r - 1][c];
            }
            if (c > 0)
            {
                sum += temp[r][c - 1];
            }
            if (c < n - 1)
            {
                sum += temp[r][c + 1];
            }
            temp[r + 1][c] = sum % 2;
            if (A[r][c] == 1 && temp[r][c] == 0)
            {
                return INF;
            }
        }
    }
    int cnt = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (A[r][c] != temp[r][c])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{

    // 輸入幾組資料
    int t;
    scanf("%d", &t);

    for (int Kase = 0; Kase < t; Kase++)
    {

        // 輸入資料
        // 正方形邊長
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }

        int ans = INF;

        // s 是列舉第一row所有可能的值
        // 1<<n , 左移運算子 ， 1向左移n個
        // 例 1<<3 = 0001 -> 1000 == 8
        // 剛好會是 2^n

        // 設 n=3
        // s < (1<<n) == s < 8 
        // 用二進位表示剛好會等於
        // 000
        // 001
        // 010
        // .
        // .
        // .
        // 111
        // 會是邊長 3 正方形第一row的所有可能
        // 帶進去一一用迴圈檢查是否可行，與變換次數
        for (int s = 0; s < (1 << n); s++)
        {
            // 選最小的
            ans = min(ans, check(s));
        }
        if (ans == INF)
        {
            ans = -1;
        }
        printf("case %d : %d\n", Kase+1, ans);
    }
    // cout << "這個程式執行時間為：" << (end_time - star_time) << "ms." << endl;
    return 0;
}
