//https://www.luogu.com.cn/problem/P8783
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

#define int long long
#define N 510

int n, m, k;
int mat[N][N];
int f[N][N]; //前缀和
int cnt;

signed main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    //初始化
    f[0][0] = mat[0][0];
    for (int i = 1; i < m; i++)
        f[0][i] = f[0][i - 1] + mat[0][i];
    for (int i = 1; i < n; i++)
        f[i][0] = f[i - 1][0] + mat[i][0];

    for (int i = 1; i < n; i++) //求前缀和
        for (int j = 1; j < m; j++)
            f[i][j] = f[i - 1][j] + f[i][j - 1] + mat[i][j] - f[i - 1][j - 1];
        
    //枚举所有矩阵
    for (int i = 0; i < n; i++) //枚举矩阵上界
    {
        for (int j = i; j < n; j++) //枚举矩阵下界
        {
            int l = 0, r = 0; //矩阵左右界
            int ans = 0; //记录当前上下界内符合条件的子矩阵个数
            while (r < m)
            {
                int sum = f[j][r];
                if (i - 1 >= 0) //判断是否越界
                    sum -= f[i - 1][r];
                if (l - 1 >= 0)
                    sum -= f[j][l - 1];
                if (i - 1 >= 0 && l - 1 >= 0)
                    sum += f[i - 1][l - 1];

                if (sum <= k)
                {
                    ans = ans + (r - l + 1);
                    r++;
                }
                else 
                {
                    l++;
                    if (l > r)
                        r = l;
                }
            }
            cnt += ans;
        }
    }
    cout << cnt << endl;
    return 0;
}