//https://www.acwing.com/problem/content/839/
#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m;
int p[N], cnt[N];

int find(int x) //找根节点+路径压缩
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        p[i] = i, cnt[i] = 1;
    for(int i = 0; i < m; i++)
    {
        string c;
        int a, b;
        cin >> c;
        if(c == "C")
        {
            cin >> a >> b;
            if(a != b && find(a) != find(b)) //ab不在一个连通块
                cnt[p[a]] += cnt[p[b]], p[p[b]] = p[a]; //把b所在集合的根连接到a所在集合
        }
        else if(c == "Q1")
        {
            cin >> a >> b;
            if(a == b || find(a) == find(b)) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}