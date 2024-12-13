#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 210
#define M 20010

int n, m, k;
int g[N][N]; //�洢��i��j�����·������
int path[N][N]; //path[i][j]�洢��i��j���·�����յ� �� ǰ�̽ڵ�

void Floyd()
{
    for(int i = 1; i <= n; i++)
	{
	    g[i][i] = 0; //�Լ����Լ���·����������Ϊ0
	}
	
	for(int k = 1; k <= n; k++) //�����i����k��j�����·��
	{
		for (int i = 1; i <= n; i++) //��i��
		{
			for (int j = 1; j <= n; j++) //��j��
			{
				if(i == j || i == k || j == k) //�������
					continue;

				if(g[i][k] + g[k][j] < g[i][j]) //��i����k��j�����·�� �� ԭ�ȴ�i��j�����·������
				{
					g[i][j] = g[i][k] + g[k][j]; //���´�i��j�����·��
					path[i][j] = path[k][j]; //���´�i��j���·�����յ� �� ǰ�̽ڵ�
				}
			}
		}
	}
}

void solve()
{
	//��ʼ������g��path
    memset(g, 0x3f, sizeof g); 
	memset(path, -1, sizeof path);

	cin >> n >> m >> k;
	for(int i = 0;i < m; i++)
	{
	    int a, b, w;
	    cin >> a >> b >> w;
	    g[a][b] = min(g[a][b], w); //���ܴ����ر�
		path[a][b] = a; //��ʼʱ��a��b���·���յ��ǰ�̽ڵ����a����
	}

	Floyd(); //Floyd�㷨

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