//https://www.acwing.com/problem/content/1029/
#include <bits/stdc++.h>
using namespace std;

#define N 15

int n;
int g[N][N];
int f[2*N][N][N]; //f[k][i1][i2]��������·���ֱ��(1,1)��(i1,k-i1)(i2,k-i2)����󳤶Ⱥͣ�kΪ��������֮�ͣ�

int main()
{
    cin >> n;
    int x, y, c;
    while(cin >> x >> y >> c, x || y || c)
        g[x][y] = c;
    
    for(int k = 2; k <= 2*n; k++)
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++)
            {
                //1.��һ��·�����һ�����£��ڶ���·�����һ������
                //2.��һ��·�����һ�����£��ڶ���·�����һ������
                //3.��һ��·�����һ�����ң��ڶ���·�����һ������
                //4.��һ��·�����һ�����ң��ڶ���·�����һ������
                if(k-i1 >= 1 && k-i1 <= n && k-i2 >= 1 && k-i2 <= n)
                {
                    f[k][i1][i2] = max(max(max(f[k-1][i1-1][i2-1], f[k-1][i1-1][i2]), 
                                                f[k-1][i1][i2-1]), f[k-1][i1][i2]) + g[i1][k-i1];
                    if(i1 != i2) //(i1,k-i1)��(i2,k-i2)���غ�
                        f[k][i1][i2] += g[i2][k-i2];
                }
            }
    cout << f[2*n][n][n] << endl;
    return 0;
}