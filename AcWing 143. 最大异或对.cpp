//https://www.acwing.com/problem/content/145/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100010;

int n, idx, ans;
int trie[N*31][2]; //Ai转换为二进制后最多31位（小于2e31）
int a[N];

void insert(int x) //插入字典树
{
    int p = 0;
    for(int i = 30; ~i; i--) //从高位取到低位
    {
        int u = (x >> i) & 1; //取对应位的值
        if(!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
    }
}

int query(int x) //字典树查询（尽量往相反走）
{
    int p = 0;
    int res = 0;
    for(int i = 30; ~i; i--)
    {
        int u = (x >> i) & 1;
        if(trie[p][!u]) //如果对应位相反的节点存在
        {
            if(!u) res += 1 << i; //按路径把位提取出来
            p = trie[p][!u];
        } //不存在则只能走对应位相同的节点
        else
        {
            if(u) res += 1 << i;
            p = trie[p][u];
        }
    }
    return res;
}

signed main()
{
    //暴力优化：字典树
    //将所有Ai化为二进制数字，对于每个Ai，都在所有整数之中找出和它异或后的最大值，最后在对所有最大值取最大值
    //优化：将二进制数字存到字典树中，对于每个二进制Ai，在查找时'尽量'查找每一位都和其不同的路径，最后得到的结果就是该轮的最优解
    //假设一个数字是1101001...，我们就要尽量找到一个0010110...的数字，如果在某一位上相反的数字不存在，就只能走相同数字的路径
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int ret = query(a[i]); //取出目标整数
        ans = max(ans, a[i] ^ ret); //在所有最大值中取最大值
    }
    cout << ans << endl;
    return 0;
}