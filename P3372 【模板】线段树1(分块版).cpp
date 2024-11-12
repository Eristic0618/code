//https://www.luogu.com.cn/problem/P3372
//�ֿ��㷨
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int MAXN = 5e5 + 10; //Ԫ���������
const int MAXM = 710; //����������
int n, m, a[MAXN];//Ԫ�ظ����������������洢Ԫ�ص����� 
int len, tot, l[MAXM], r[MAXM], belong[MAXN];//��ĳ��ȡ�������������ұ߽硢ÿ��Ԫ�������Ŀ�
int sum[MAXM], b[MAXM], add[MAXM];//������ĺ͡����ǰ׺��

void init() //��ʼ����
{
	len = sqrt(n), tot = (n-1) / len + 1;//��ĳ��ȶ�n��������������ȡ��
	for(int i = 1;i <= tot;i++) l[i] = r[i-1]+1, r[i] = i * len;//��¼������ұ߽�
	r[tot] = n;//���һ����ĳ��ȿ���С��len
	for(int i = 1;i <= tot;i++)
	{
		for(int j = l[i];j <= r[i];j++)
			belong[j] = i, sum[i] += a[j];//��¼ÿ��Ԫ�������Ŀ�Ϳ�������Ԫ�صĺ�
		b[i] = b[i-1] + sum[i];//��¼���ǰ׺��
	}
}

void modify(int ql, int qr, int x)//�����޸�-����k��Ԫ�ؼ���x
{
	int p = belong[ql], q = belong[qr];//��¼���Ҷ˵����ڵĿ�
	if(p == q)//�����ͬһ���飺����
	{
		for(int i = ql;i <= qr;i++) a[i] += x, sum[p] += x;//����Ԫ��ֵ����ĺ� 
		for(int i = p;i <= tot;i++) b[i] = b[i-1] + sum[i];//����ǰ׺�� 
		return;
	}
	for(int i = ql;i <= r[p];i++) a[i] += x, sum[p] += x;//�������ڿ�p��q�Ĳ����γ�һ���������Ԫ�� 
	for(int i = qr;i >= l[q];i--) a[i] += x, sum[q] += x;
	for(int i = p + 1;i <= q - 1;i++) add[i] += x, sum[i] += len * x;//���������������Ԫ��+x������sum
	for(int i = p;i <= tot;i++) b[i] = b[i-1] + sum[i];//����ǰ׺�� 
}

int query(int ql, int qr)//ѯ��
{
	int p = belong[ql], q = belong[qr];//��¼���Ҷ˵����ڵĿ�
	int ans = 0;
	if(p == q)//�����ͬһ���飺����
	{
		for(int i = ql;i <= qr;i++) ans += a[i] + add[p];
		return ans;
	}
	ans = b[q-1] - b[p];//��ǰ׺�ͼ���p��q֮�����е�������֮��
	for(int i = ql;i <= r[p];i++) ans += a[i] + add[p];
	for(int i = qr;i >= l[q];i--) ans += a[i] + add[q];//����ʣ��Ԫ��
	return ans;
}

void solve()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	init();
	for(int i = 1;i <= m;i++)
	{
		int q, ql, qr, x;
		cin >> q >> ql >> qr;
		if(q == 1)
		{
			cin >> x;
			modify(ql, qr, x);  
		}
		else cout << query(ql, qr) << endl;
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