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
//对于第i行，我们有两个情况可以改变第i行某盏灯的状态：直接对该盏灯进行操作，或者对下一行同一列的灯进行操作，间接影响这盏灯
//例如第一行的操作确定后，要改变第一行的灯，就只能通过对第二行的灯进行操作，所以我们在对第二行进行操作时就要确保第一行的灯全1
//同理，操作第i行的时候，我们要确保进行的操作能够让i-1行的灯全为1
//所以我们可以先通过dfs枚举第一行的所有操作状态，然后递推第二行、第三行，直到最后一行进行完操作后，判断最后一行是否为全1
void dfs(int u, int step)
{
    if(u == 6)
    {
        memcpy(backup, g, sizeof g); //备份
        //第1行已确定，从第2行开始进行操作
        for(int i = 2; i <= 5; i++)
            for(int j = 1; j <= 5; j++) //枚举列
                if(g[i-1][j] == '0') //上一行对应列为0
                {
                    turn(i, j); //这一行对应列进行操作，让上一行的对应列变为1
                    step++; //操作数+1
                }
        bool flag = true;
        for(int i = 1; i <= 5; i++) //判断最后一行（第五行）是否为全1
            if(g[5][i] == '0') flag = false;
        if(flag) res = min(res, step); //如果为全1，记录操作数的最小值
        memcpy(g, backup, sizeof backup); //恢复
        return;
    }
    //枚举第1行的所有可能结果
    dfs(u+1, step); //第1行第u列不按
    
    //第1行第u列按下
    turn(1, u);
    dfs(u+1, step+1);
    turn(1, u); //回溯
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