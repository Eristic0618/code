//https://www.acwing.com/problem/content/6125/
#include <iostream>
#include <vector>
using namespace std;

int n, q;
int cnt;

int main()
{
    cin >> n >> q;
    //三个数组分别记录对应坐标轴的奶酪块剩余大小，为0则代表这一条被挖完了
    vector<vector<int>> a_x(n, vector<int>(n, n));
    vector<vector<int>> a_y(n, vector<int>(n, n));
    vector<vector<int>> a_z(n, vector<int>(n, n));
    for(int i = 0;i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a_x[z][y]--;
        if(a_x[z][y] == 0) 
            cnt++;
        a_y[x][z]--;
        if(a_y[x][z] == 0)
            cnt++;
        a_z[x][y]--;
        if(a_z[x][y] == 0)
            cnt++;
        cout << cnt << endl;
    }
    return 0;
}