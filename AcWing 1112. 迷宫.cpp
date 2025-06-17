//https://www.acwing.com/problem/content/1114/
#include <iostream>
#include <cstring>
#define endl '\n'
#define int long long
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 110

int n, x1, y1, x2, y2;
char g[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool st[N][N];

bool dfs(int x, int y)
{
	if(x == x2 && y == y2) return true; //�ߵ��յ� 	
	st[x][y] = true;
	for(int i = 0; i < 4; i++) //�ĸ�����
	{
		int tx = dx[i] + x, ty = dy[i] + y;
		if(tx >= 0 && tx < n && ty >= 0 && ty < n && g[tx][ty] == '.' && !st[tx][ty]) //��Խ�硢����ͨ����δ�����ʹ� 
		{
			if(dfs(tx, ty)) return true; //��֦ 
		}	
	} 
	return false;
}

void solve()
{
	memset(st, 0, sizeof st);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> g[i];
	cin >> x1 >> y1 >> x2 >> y2;
//	if(x1 == x2 && y1 == y2) //���Բ��У������������жϷ������ж��Ƿ��غϣ��������ֱ��ȥ����dfs���жϣ� 
//	{
//		cout << "YES" << endl;
//		return;
//	}
	if(g[x1][y1] == '#' || g[x2][y2] == '#')
	{
		cout << "NO" << endl;
		return;
	}
	if(dfs(x1, y1)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}