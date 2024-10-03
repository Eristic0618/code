// https://www.acwing.com/problem/content/838/
#include <iostream>
using namespace std;
#define N 100010

int n, m;
int p[N];

int find(int x) // 找根节点+路径压缩
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i; // 根的父节点=自己
    for (int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
            p[find(a)] = find(b); // 根节点相连--合并集合
        else
        {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}