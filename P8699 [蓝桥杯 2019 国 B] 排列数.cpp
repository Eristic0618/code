//https://www.luogu.com.cn/problem/P8699
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 505

int dp[N][N]; //dp[i][j]����1~i����������j���۵�ķ�����
int n, k; 

void solve()
{
	cin >> n >> k;
	dp[1][0] = 1;
	for(int i = 2; i < n; i++)
	{
		dp[i][0] = 2; //������ݼ� 
		for(int j = 0; j <= i; j++)
		{
			dp[i+1][j] += (dp[i][j] * (j+1)) % 123456; //�����j���۵㣬�Ҳ�����Ԫ�غ��������۵㣬��ֻ���ڲ���������롣�������������۵㻹��ż�����۵㣬�ɲ����λ�ö���j+1��
			dp[i+1][j+1] += (dp[i][j] * 2) % 123456; //ֻ��������ͷ��β��ǰ��������ʵ��ֻ����һ���۵�
			dp[i+1][j+2] += (dp[i][j] * ((i+1)-(j+1)-2)) % 123456; //ʣ������λ�ö��������������۵� 
		}
	}
	cout << dp[n][k-1] % 123456 << endl;
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