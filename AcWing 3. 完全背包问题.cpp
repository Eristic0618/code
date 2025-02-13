// https://www.acwing.com/problem/content/3/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, V;
int f[N]; // f[i]Ϊ��װ��Ʒ����Ϊiʱ�������Ʒ��ֵ
int v[N], w[N];

// ���������Ż�
int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)        // ����n����Ʒ
        for (int j = v[i]; j <= V; j++) // ���ڵ�i����Ʒ����ѡ����������˾������������Ż����ǰ��������Ϳ���ʵ��j-k*v[i]��Ч��
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V] << endl;
    return 0;
}