// https : // www.luogu.com.cn/problem/P9241
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct info // 用于存储每架飞机的三个时间
{
    info(int a, int b, int c)
        : _T(a), _D(b), _L(c)
    {
    }

    int _T; // 到达时间
    int _D; // 最大盘旋时间
    int _L; // 降落花费的时间
};

static vector<bool> visit; // 用于检测飞机是否已经降落
static vector<info> plane; // 存储飞机的各项时间
static int n;              // 飞机个数

bool dfs(int i, int time) // dfs返回bool类型的值，如果某条路径走得通则返回true，走不通则false
{
    if (i == n) // 当i==n，说明飞机全部降落
        return true;
    for (int k = 0; k < n; k++) // 通过遍历进行飞机的全排列，逐个排除无法成功降落的飞机顺序
    {
        if (!visit[k] && plane[k]._T + plane[k]._D >= time) // 降落条件：没有降落过 且 飞机到达的时间+可以继续盘旋的时间>=前面所有飞机降落花费的时间
        {
            visit[k] = true; // 标记飞机已经降落
            if (dfs(i + 1, max(time, plane[k]._T) + plane[k]._L)) // i+1记录降落的飞机数量，而不是k+1，如果飞机到达的时间在time之后，则以到达时间为标准+降落花费的时间
                return true;
            visit[k] = false; // 到这里，说明先降落第k架飞机的策略行不通，回溯到飞机未降落的状态
        }
    }
    return false; // 循环结束，说明该层递归中无论选择哪架飞机降落都无法成功，则返回false
}

int main()
{
    int t;
    cin >> t;
    while (t--) // 当t为0说明全部测试组完毕
    {
        cin >> n;
        visit = vector<bool>(n, false);
        for (int i = 0; i < n; i++) // 存入n架飞机的各项时间
        {
            int a, b, c;
            cin >> a >> b >> c;
            plane.push_back(info(a, b, c));
        }
        if (dfs(0, 0)) // 如果存在可以成功降落的飞机顺序，则打印YES
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        plane.clear(); // 清除plane中的数据，为下一组做准备
    }
    return 0;
}