//https://www.acwing.com/problem/content/243/
#include <iostream>
#include <cstring>
using namespace std;

#define N 200020
#define int long long

int n, res1, res2;
int a[N];
int tr[N]; //��״����洢ĳһʱ�̳��ֵ�y
int Greater[N], lower[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

//˼·��ͨ��ͳ��ĳ��y�������ߴ�������ĸ�������˼�ΪV�����������֮ͬ��
//ͳ�Ƹ����ķ�������״����
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) //��ǰ��������i��y��ǰ����y��С��y�ĸ���
    {
        int y = a[i];
        Greater[i] = sum(n) - sum(y); //yֵ��һ����������tr�ģ����ĳһʱ��n��ǰ׺�ͼ�ȥy��ǰ׺�ͣ���Ϊ���ʱ��֮ǰ���ֹ��Ĵ���y����
        lower[i] = sum(y-1); //ͬ��
        add(y, 1); //��y����tr
    }
    
    memset(tr, 0, sizeof tr); //���tr����ʼ�����i��y�������y��С�ڵĸ���
    for(int i = n; i > 0; i--) //�Ӻ���ǰ����
    {
        int y = a[i];
        res1 += Greater[i] * (sum(n) - sum(y)); //��i��y��ǰ����������������yֵ������˼�ΪV�������
        res2 += lower[i] * sum(y-1); 
        add(y, 1); 
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}
