// https://www.acwing.com/problem/content/851/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510;

int n, m, dis[N];
int path[N][N];
bool check[N];

int dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!check[j] && (mini == -1 || dis[mini] > dis[j]))
                mini = j;
        }

        check[mini] = true;

        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[mini] + path[mini][j]);
        }
    }
    if (dis[n] == 0x3f3f3f3f)
        return -1;
    return dis[n];
}

int main()
{
    memset(path, 0x3f, sizeof path);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = min(path[a][b], c);
    }

    int t = dijkstra();

    cout << t << endl;
    return 0;
}