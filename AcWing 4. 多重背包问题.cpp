//https://www.acwing.com/problem/content/4/
#include <bits/stdc++.h>
using namespace std;

#define N 110

int n, V;
int v[N], w[N], s[N];
int f[N]; //f[i]代表总体积为i的所有情况中所持物品的最大价值(空间优化)

int main()
{
    cin >> n >> V;
    for(int i = 1;i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    
    for(int i = 1;i <= n; i++) //n件物品
    {
        for(int j = V; j >= v[i]; j--) //总体积j
        {
            for(int k = 1; k <= s[i] && j - v[i]*k >= 0; k++) //最多选s[i]个，这里不能和完全背包一样带公式因为数量有限制
                f[j] = max(f[j], f[j - v[i] * k] + w[i] * k); 
        }
    }
    cout << f[V] << endl;
    return 0;
}