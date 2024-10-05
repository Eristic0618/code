// https://www.acwing.com/problem/content/853/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m, dis[N];
int e[N], h[N], w[N], ne[N], idx;
bool check[N];

int spfa()
{
    memset(dis, 0x3f, sizeof dis); // 初始化距离
    dis[1] = 0;
    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        check[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i]) // 更新为更短距离，将对应点入队
            {
                dis[j] = dis[t] + w[i];
                if (!check[j])
                {
                    q.push(j);
                    check[j] = true;
                }
            }
        }
    }
    return dis[n];
}

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = spfa();

    if (t == 0x3f3f3f3f)
        cout << "impossible";
    else
        cout << t;
    return 0;
}