// https://www.acwing.com/problem/content/852/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 202020;

int n, m, dis[N];
int e[N], h[N], w[N], ne[N], idx;
bool check[N];

int dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (check[ver])
            continue;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > distance + w[i])
            {
                dis[j] = distance + w[i];
                heap.push({dis[j], j});
            }
        }
        check[ver] = true;
    }

    if (dis[n] == 0x3f3f3f3f)
        return -1;
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

    int t = dijkstra();

    cout << t << endl;
    return 0;
}