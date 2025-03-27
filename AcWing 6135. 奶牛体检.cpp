//https://www.acwing.com/problem/content/description/6138/
#include <iostream>
using namespace std;

#define N 7510

int n;
int a[N], b[N];
int dp[N][N]; //记录i-j区间翻转后的合法奶牛数
int c[N];

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> a[i]; //读入初始品种序列
    }
    int cnt = 0;
    for(int i = 0;i < n; i++)
    {
        cin >> b[i]; //读入兽医指定序列
        if(a[i] == b[i])
            cnt++; //记录原序列的合法奶牛数
    }
    //注意！因为要从小区间扩展到大区间，必须先遍历区间长度
    for(int i = 1;i <= n; i++) //区间长度
    {
        for(int j = 0;j+i-1 < n; j++) //区间起始位置
        {
            if(i == 1) //区间长度为1
            {
                dp[j][j] = cnt;
                c[cnt]++;
                continue;
            }
            if(i == 2 || i == 3) //区间大小为2或3
                dp[j][j+i-1] = cnt;
            else
                dp[j][j+i-1] = dp[j+1][j+i-2]; //状态转移
            //判断数量是否变化
            if(a[j] == b[j] && a[j+i-1] != b[j])
                dp[j][j+i-1]--;
            if(a[j+i-1] == b[j+i-1] && a[j] != b[j+i-1])
                dp[j][j+i-1]--;
            if(a[j] != b[j] && a[j+i-1] == b[j])
                dp[j][j+i-1]++;
            if(a[j+i-1] != b[j+i-1] && a[j] == b[j+i-1])
                dp[j][j+i-1]++;
            c[dp[j][j+i-1]]++;
        }
    }
    for(int i = 0;i <= n; i++)
        cout << c[i] << endl;
    return 0;
}