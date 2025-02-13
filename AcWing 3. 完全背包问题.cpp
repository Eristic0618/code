// https://www.acwing.com/problem/content/3/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, V;
int f[N]; // f[i]为所装物品质量为i时的最大物品价值
int v[N], w[N];

// 滚动数组优化
int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)        // 遍历n件物品
        for (int j = v[i]; j <= V; j++) // 对于第i个物品可以选无数个，因此经过滚动数组优化后从前往后遍历就可以实现j-k*v[i]的效果
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V] << endl;
    return 0;
}