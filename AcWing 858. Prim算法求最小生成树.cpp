#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 510
#define M 1000010

int	n, m;
int dist[N]; //�ڵ㵽��ͨ�����̾��� 
int g[N][N]; //�ڽӾ���
bool st[N];  //�ж�ĳ�ڵ��Ƿ�����ͨ���� 

int Prim()
{
	memset(dist, 0x3f, sizeof dist); //��ʼ��dist���� 
	dist[1] = 0;
	
	int res = 0; //��С��������Ȩ�� 
	for(int i = 0; i < n; i++) //��ʼ�ڵ��Ѽ�����ͨ�飬����ʣ��n-1���ڵ�
	{
		int t = -1; //��ǵ�ǰ����������ͨ�������С�Ľڵ��� 
		for(int j = 1; j <= n; j++) //�������нڵ� 
		{
			if(!st[j] && (t == -1 || dist[t] > dist[j])) //�ڵ�j������ͨ���� �� ��ǰδѡ��ڵ��ڵ�j����Ƚڵ�t����
				t = j; //����t 
		}
		//����ѭ������ʱ�ڵ�t���� ʣ�����в�������ͨ���еĽڵ� �� ������ͨ����̵Ľڵ� 
		if(dist[t] > INF / 2) return INF; // dist[t]��Ϊ���ֵ��˵��ʣ��ڵ㲻����ͨ������
		
		res += dist[t]; //��t������ͨ��ľ�������Ȩ�� 
		
		for(int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]); //����ʣ��ڵ㵽��ͨ�����̾��� 
		}
		
		st[t] = true; //���ڵ�t������ͨ�� 
	}
	return res;
}

void solve()
{
	cin >> n >> m;
	
	memset(g, 0x3f, sizeof g); //����Ȩ��ȫ����ʼ��Ϊ���ֵ 
	for(int i = 0;i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b], w); //����ͼ+���ܴ����ر� 
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