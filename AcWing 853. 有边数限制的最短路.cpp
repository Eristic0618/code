// https://www.acwing.com/problem/content/855/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, M = 10010;

struct edge
{
    int a, b, w;
} edges[M];

int n, m, k;
int dict[N], backup[N];

int bellman_ford()
{
    memset(dict, 0x3f, sizeof dict);
    dict[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dict, sizeof dict);
        for (int j = 0; j < m; j++)
        {
            int a, b, w;
            a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dict[b] = min(dict[b], backup[a] + w);
        }
    }
    return dict[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int ans = bellman_ford();

    if (ans > 0x3f3f3f3f / 2)
        cout << "impossible";
    else
        cout << ans;
    return 0;
}