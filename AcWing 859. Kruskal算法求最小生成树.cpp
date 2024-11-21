#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;
 
#define N 1000010
#define M 200020
 
int n, m;
int f[N]; //���鼯 
 
struct edge
{
	int a, b, w;
}e[M];
 
int cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}
 
int check(int num) //��ѯĳ���ڵ����ڼ��ϵĸ� 
{
	if(f[num] != num) return f[num] = check(f[num]); 
	//ѹ��·������·����ÿ���ڵ�ĸ��׶��޸�Ϊ���ڵ� 
	return num;
}
 
void merge(int a, int b) //�ϲ������ڵ����ڼ���
{
	if(a == b) //a,b��ͬ 
		return;
	f[a] = b; //a�ĸ��ڵ���Ϊb 
} 
 
bool same(int a, int b) //�ж������ڵ��Ƿ���ͬһ���� 
{
	if(f[a] == f[b]) return true; //a,b���ڵ���ͬ��˵����ͬһ���� 
	else return false;
}
 
int Kruskal()
{
	for(int i = 1; i <= n; i++) //��ʼ�����鼯 
	{
		f[i] = i;
	}
	sort(e, e+m, cmp); //���ձ�Ȩ�������� 
	int cnt = 0; //ͳ�Ƶ�ǰѡ���˶������� 
	int ans = 0; //��С��������Ȩ�� 
	for(int i = 0;i < m; i++) //�������б� 
	{
		int a = e[i].a, b = e[i].b, w = e[i].w;
		a = check(a), b = check(b);
		if(same(a, b)) //a��b����ͬһ��ͨ����
			continue;
		//a��b������ͬһ��ͨ����
		ans += w; //ѡ�������
		merge(a, b); //��a��b������ͨ�����ϲ� 
		cnt++;
		if(cnt == n-1) //��ѡ��n-1���� 
			break;
	} 
	if(cnt < n-1) //��������
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
		e[i] = {x, y, z}; //��� 
	}
	
	int ans = Kruskal(); //Kruskal�㷨
	if(ans == -1) //����ͨ 
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