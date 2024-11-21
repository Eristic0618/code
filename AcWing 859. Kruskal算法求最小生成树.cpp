#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;
 
#define N 1000010
#define M 200020
 
int n, m;
int f[N]; //并查集 
 
struct edge
{
	int a, b, w;
}e[M];
 
int cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}
 
int check(int num) //查询某个节点所在集合的根 
{
	if(f[num] != num) return f[num] = check(f[num]); 
	//压缩路径：将路径上每个节点的父亲都修改为根节点 
	return num;
}
 
void merge(int a, int b) //合并两个节点所在集合
{
	if(a == b) //a,b相同 
		return;
	f[a] = b; //a的父节点置为b 
} 
 
bool same(int a, int b) //判断两个节点是否在同一集合 
{
	if(f[a] == f[b]) return true; //a,b父节点相同，说明在同一集合 
	else return false;
}
 
int Kruskal()
{
	for(int i = 1; i <= n; i++) //初始化并查集 
	{
		f[i] = i;
	}
	sort(e, e+m, cmp); //按照边权升序排序 
	int cnt = 0; //统计当前选择了多少条边 
	int ans = 0; //最小生成树边权和 
	for(int i = 0;i < m; i++) //遍历所有边 
	{
		int a = e[i].a, b = e[i].b, w = e[i].w;
		a = check(a), b = check(b);
		if(same(a, b)) //a与b处于同一连通分量
			continue;
		//a与b不处于同一连通分量
		ans += w; //选择该条边
		merge(a, b); //将a，b所在连通分量合并 
		cnt++;
		if(cnt == n-1) //已选择n-1条边 
			break;
	} 
	if(cnt < n-1) //边数不足
		return -1;
	return ans; 
}
 
void solve()
{
	cin >> n >> m;
	for(int i = 0;i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		e[i] = {x, y, z}; //存边 
	}
	
	int ans = Kruskal(); //Kruskal算法
	if(ans == -1) //不连通 
		cout << "impossible" << endl;
	else
		cout << ans << endl;
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