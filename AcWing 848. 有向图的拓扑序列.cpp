// https://www.acwing.com/problem/content/850/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 100010;

int n, m;
int e[N], ne[N], h[N], idx;
int d[N];
queue<int> q;
vector<int> ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.push(i);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
                q.push(j);
        }
    }
    return ans.size() == n;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (topsort())
    {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}