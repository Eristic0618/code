//https://www.acwing.com/problem/content/description/97/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 510;

int n, res;
char g[10][10], backup[10][10];
int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};

void turn(int x, int y)
{
    for(int i = 0; i < 5; i++)
        g[x + dx[i]][y + dy[i]] ^= 1;
}
//���ڵ�i�У�����������������Ըı��i��ĳյ�Ƶ�״̬��ֱ�ӶԸ�յ�ƽ��в��������߶���һ��ͬһ�еĵƽ��в��������Ӱ����յ��
//�����һ�еĲ���ȷ����Ҫ�ı��һ�еĵƣ���ֻ��ͨ���Եڶ��еĵƽ��в��������������ڶԵڶ��н��в���ʱ��Ҫȷ����һ�еĵ�ȫ1
//ͬ��������i�е�ʱ������Ҫȷ�����еĲ����ܹ���i-1�еĵ�ȫΪ1
//�������ǿ�����ͨ��dfsö�ٵ�һ�е����в���״̬��Ȼ����Ƶڶ��С������У�ֱ�����һ�н�����������ж����һ���Ƿ�Ϊȫ1
void dfs(int u, int step)
{
    if(u == 6)
    {
        memcpy(backup, g, sizeof g); //����
        //��1����ȷ�����ӵ�2�п�ʼ���в���
        for(int i = 2; i <= 5; i++)
            for(int j = 1; j <= 5; j++) //ö����
                if(g[i-1][j] == '0') //��һ�ж�Ӧ��Ϊ0
                {
                    turn(i, j); //��һ�ж�Ӧ�н��в���������һ�еĶ�Ӧ�б�Ϊ1
                    step++; //������+1
                }
        bool flag = true;
        for(int i = 1; i <= 5; i++) //�ж����һ�У������У��Ƿ�Ϊȫ1
            if(g[5][i] == '0') flag = false;
        if(flag) res = min(res, step); //���Ϊȫ1����¼����������Сֵ
        memcpy(g, backup, sizeof backup); //�ָ�
        return;
    }
    //ö�ٵ�1�е����п��ܽ��
    dfs(u+1, step); //��1�е�u�в���
    
    //��1�е�u�а���
    turn(1, u);
    dfs(u+1, step+1);
    turn(1, u); //����
}

int main()
{
    cin >> n;
    while(n--)
    {
        res = 1e9;
        for(int i = 1; i <= 5; i++)
            for(int j = 1; j <= 5; j++) 
                cin >> g[i][j];
        getchar();
        dfs(1, 0);
        if(res > 6) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}