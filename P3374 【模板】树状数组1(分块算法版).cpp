//https://www.luogu.com.cn/problem/P3374
//分块算法
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int MAXN = 5e5 + 10; //元素最大数量
const int MAXM = 710; //块的最大数量
int n, m, a[MAXN];//元素个数、操作个数、存储元素的数组 
int len, tot, l[MAXM], r[MAXM], belong[MAXN];//块的长度、总数、块的左右边界、每个元素所属的块
int sum[MAXM], b[MAXM];//单个块的和、块的前缀和

void init() //初始化块
{
	len = sqrt(n), tot = (n-1) / len + 1;//块的长度对n开方，数量向上取整
	for(int i = 1;i <= tot;i++) l[i] = r[i-1]+1, r[i] = i * len;//记录块的左右边界
	r[tot] = n;//最后一个块的长度可能小于len
	for(int i = 1;i <= tot;i++)
	{
		for(int j = l[i];j <= r[i];j++)
			belong[j] = i, sum[i] += a[j];//记录每个元素所属的块和块中所有元素的和
		b[i] = b[i-1] + sum[i];//记录块的前缀和
	}
}

void modify(int k, int x)//单点修改-给第k个元素加上x
{
	sum[belong[k]] += x;//修改块和
	a[k] += x;//单点修改
	for(int i = belong[k];i <= tot;i++)
		b[i] += x;//从k所在的块到最后一个块的前缀和全部都要修改
}

int query(int ql, int qr)//询问
{
	int p = belong[ql], q = belong[qr];//记录左右端点所在的块
	int ans = 0;
	if(p == q)//如果在同一个块：暴力
	{
		for(int i = ql;i <= qr;i++) ans += a[i];
		return ans;
	}
	ans = b[q-1] - b[p];//用前缀和计算p和q之间所有的完整块之和
	for(int i = ql;i <= r[p];i++) ans += a[i];
	for(int i = qr;i >= l[q];i--) ans += a[i];//计算剩余元素
	return ans;
}

void solve()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	init();
	for(int i = 1;i <= m;i++)
	{
		int q, x, y;
		cin >> q >> x >> y;
		if(q == 1) modify(x, y);
		else cout << query(x, y) << endl;
	}
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}