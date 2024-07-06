// https://www.luogu.com.cn/problem/P8598
// ��Ŀ����
// ĳ���ܵ�λ�·���ĳ��Ʊ�ݣ���Ҫ������ȫ���ջء�
// ��Ŀ����
// ÿ��Ʊ����Ψһ�� ID �ţ�ȫ������Ʊ�ݵ� ID ���������ģ��� ID �Ŀ�ʼ���������ѡ���ġ���Ϊ������Ա�������¼�� ID �ŵ�ʱ������һ�����������ĳ�� ID �Ϻţ�����һ�� ID �غš�
// ���������ͨ����̣��ҳ��Ϻŵ� ID ���غŵ� ID��
// ���ݱ�֤�ϺŲ����ܷ�����������С�š�
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int m = 0, n = 0;
    vector<int> hash(10000, 0);
    int x;
    int min = INT_MAX, amount = 0;
    while (cin >> x)
    {
        if (x < min)
            min = x;
        hash[x]++;
        amount++;
    }
    for (int i = min; i < min + amount; i++)
    {
        if (hash[i] == 2)
            n = i;
        if (hash[i] && !hash[i + 1])
            m = i + 1;
        if (n && m)
            break;
    }
    cout << m << " " << n << endl;
    return 0;
}