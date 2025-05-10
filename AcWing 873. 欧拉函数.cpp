//https://www.acwing.com/problem/content/875/
#include <bits/stdc++.h>
using namespace std;

int n;
set<double> g;

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        g.clear();
        int x;
        cin >> x;
        int res = x;
        for(int j = 2; j <= x/j; j++) //�ֽ�������
        {
            if(x % j == 0)
            {
                res = res / j * (j-1); //�ȳ��ٳ�Ԥ����int��j�������x�����������Բ���ǿת
                while(x % j == 0)
                {
                    x /= j;
                }
            }
            if(x == 1)
                break;
        }
        if(x > 1)
            res = res / x * (x-1);
        
        cout << res << endl;
    }
    return 0;
}