// https://www.acwing.com/problem/content/838/
#include <iostream>
using namespace std;
#define N 100010

int n, m;
int p[N];

int find(int x) // �Ҹ��ڵ�+·��ѹ��
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i; // ���ĸ��ڵ�=�Լ�
    for (int i = 0; i < m; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
            p[find(a)] = find(b); // ���ڵ�����--�ϲ�����
        else
        {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}