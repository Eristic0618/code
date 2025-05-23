//https://www.acwing.com/problem/content/242/
#include <bits/stdc++.h>
using namespace std;

#define N 50050

int n, k, ans;
int p[N], d[N]; //d用于记录某个节点到根节点的逻辑距离

int find(int x)
{
    if(p[x] != x)
    {
        int u = p[x];
        p[x] = find(p[x]);
        d[x] += d[u];
    }
    return p[x];
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        p[i] = i;
        
    while(k--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if(x > n || y > n) ans++;
        else
        {
            int px = find(x), py = find(y);
            if(op == 1) //判断是否同类
            {
                if(px == py && (d[x] - d[y]) % 3) //都在一个集合中且逻辑距离不是3的倍数
                    ans++; //不是同类，假话
                else if(px != py) //不在一个集合中
                {
                    p[px] = py; //px与py相连
                    d[px] = d[y] - d[x]; //同余定理，(d[x]+d[px]-d[y]) % 3 == 0
                }
            }
            else //X吃Y
            {
                if(px == py && (d[x] - d[y] - 1) % 3) //在一个集合中且X到Y的逻辑距离%3不为1
                    ans++; //不能吃，假话
                else if(px != py) //不在一个集合中
                {
                    p[px] = py; //px与py相连
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}