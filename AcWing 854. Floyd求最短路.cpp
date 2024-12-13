#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 210
#define M 20010

int n, m, k;
int g[N][N]; //存储从i到j的最短路径长度
int path[N][N]; //path[i][j]存储从i到j最短路径的终点 的 前继节点

void Floyd()
{
    for(int i = 1; i <= n; i++)
	{
	    g[i][i] = 0; //自己到自己的路径长度设置为0
	}
	
	for(int k = 1; k <= n; k++) //代表从i经过k到j的最短路径
	{
		for (int i = 1; i <= n; i++) //第i行
		{
			for (int j = 1; j <= n; j++) //第j列
			{
				if(i == j || i == k || j == k) //多余情况
					continue;

				if(g[i][k] + g[k][j] < g[i][j]) //从i经过k到j的最短路径 比 原先从i到j的最短路径更短
				{
					g[i][j] = g[i][k] + g[k][j]; //更新从i到j的最短路径
					path[i][j] = path[k][j]; //更新从i到j最短路径的终点 的 前继节点
				}
			}
		}
	}
}

void solve()
{
	//初始化矩阵g和path
    memset(g, 0x3f, sizeof g); 
	memset(path, -1, sizeof path);

	cin >> n >> m >> k;
	for(int i = 0;i < m; i++)
	{
	    int a, b, w;
	    cin >> a >> b >> w;
	    g[a][b] = min(g[a][b], w); //可能存在重边
		path[a][b] = a; //初始时从a到b最短路径终点的前继节点就是a本身
	}

	Floyd(); //Floyd算法

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		if(g[a][b] > INF / 2)
			cout << "impossible" << endl;
		else
			cout << g[a][b] << endl;
	}
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}