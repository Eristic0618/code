#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 510
#define M 1000010

int	n, m;
int dist[N]; //节点到连通块的最短距离 
int g[N][N]; //邻接矩阵
bool st[N];  //判断某节点是否在连通块中 

int Prim()
{
	memset(dist, 0x3f, sizeof dist); //初始化dist数组 
	dist[1] = 0;
	
	int res = 0; //最小生成树边权和 
	for(int i = 0; i < n; i++) //起始节点已加入连通块，遍历剩余n-1个节点
	{
		int t = -1; //标记当前遍历中与连通块距离最小的节点编号 
		for(int j = 1; j <= n; j++) //遍历所有节点 
		{
			if(!st[j] && (t == -1 || dist[t] > dist[j])) //节点j不在连通块中 且 当前未选择节点或节点j距离比节点t更短
				t = j; //更新t 
		}
		//经过循环，此时节点t就是 剩余所有不属于连通块中的节点 中 距离连通块最短的节点 
		if(dist[t] > INF / 2) return INF; // dist[t]仍为最大值，说明剩余节点不与连通块连接
		
		res += dist[t]; //将t距离连通块的距离加入边权和 
		
		for(int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]); //更新剩余节点到连通块的最短距离 
		}
		
		st[t] = true; //将节点t加入连通块 
	}
	return res;
}

void solve()
{
	cin >> n >> m;
	
	memset(g, 0x3f, sizeof g); //所有权重全部初始化为最大值 
	for(int i = 0;i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b], w); //无向图+可能存在重边 
	}
	
	int ret = Prim();
	
	if(ret == INF) cout << "impossible" << endl;
	else cout << ret << endl;
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