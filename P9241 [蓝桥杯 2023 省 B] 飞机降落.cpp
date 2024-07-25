// https : // www.luogu.com.cn/problem/P9241
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct info // ���ڴ洢ÿ�ܷɻ�������ʱ��
{
    info(int a, int b, int c)
        : _T(a), _D(b), _L(c)
    {
    }

    int _T; // ����ʱ��
    int _D; // �������ʱ��
    int _L; // ���仨�ѵ�ʱ��
};

static vector<bool> visit; // ���ڼ��ɻ��Ƿ��Ѿ�����
static vector<info> plane; // �洢�ɻ��ĸ���ʱ��
static int n;              // �ɻ�����

bool dfs(int i, int time) // dfs����bool���͵�ֵ�����ĳ��·���ߵ�ͨ�򷵻�true���߲�ͨ��false
{
    if (i == n) // ��i==n��˵���ɻ�ȫ������
        return true;
    for (int k = 0; k < n; k++) // ͨ���������зɻ���ȫ���У�����ų��޷��ɹ�����ķɻ�˳��
    {
        if (!visit[k] && plane[k]._T + plane[k]._D >= time) // ����������û�н���� �� �ɻ������ʱ��+���Լ���������ʱ��>=ǰ�����зɻ����仨�ѵ�ʱ��
        {
            visit[k] = true; // ��Ƿɻ��Ѿ�����
            if (dfs(i + 1, max(time, plane[k]._T) + plane[k]._L)) // i+1��¼����ķɻ�������������k+1������ɻ������ʱ����time֮�����Ե���ʱ��Ϊ��׼+���仨�ѵ�ʱ��
                return true;
            visit[k] = false; // �����˵���Ƚ����k�ܷɻ��Ĳ����в�ͨ�����ݵ��ɻ�δ�����״̬
        }
    }
    return false; // ѭ��������˵���ò�ݹ�������ѡ���ļܷɻ����䶼�޷��ɹ����򷵻�false
}

int main()
{
    int t;
    cin >> t;
    while (t--) // ��tΪ0˵��ȫ�����������
    {
        cin >> n;
        visit = vector<bool>(n, false);
        for (int i = 0; i < n; i++) // ����n�ܷɻ��ĸ���ʱ��
        {
            int a, b, c;
            cin >> a >> b >> c;
            plane.push_back(info(a, b, c));
        }
        if (dfs(0, 0)) // ������ڿ��Գɹ�����ķɻ�˳�����ӡYES
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        plane.clear(); // ���plane�е����ݣ�Ϊ��һ����׼��
    }
    return 0;
}