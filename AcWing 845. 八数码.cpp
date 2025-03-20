// https://www.acwing.com/problem/content/847/
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int bfs(string start)
{
    queue<string> q;
    unordered_map<string, int> dist; // 距离
    q.push(start);
    dist[start] = 0;                                  // 起始字符串到自己的距离为0
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}; // 偏移数组

    string end = "12345678x";

    while (q.size())
    {
        string f = q.front(); // 取出队头字符串
        q.pop();

        int distance = dist[f]; // 取f到初状态的距离
        if (f == end)
            return distance;

        int index = f.find('x');          // 查找x在字符串中的位置
        int x = index / 3, y = index % 3; // 把字符串还原为3x3方格

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                string temp = f;
                int new_index = a * 3 + b;          // 待交换的目标在字符串中的位置
                swap(temp[index], temp[new_index]); // 交换字符
                if (dist.count(temp) == 0)          // 新状态
                {
                    q.push(temp);              // 将新状态入队列
                    dist[temp] = distance + 1; // 距离加1
                }
            }
        }
    }
    return -1; // 不存在解决方案
}

int main()
{
    string start; // 起始字符串
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }
    int ret = bfs(start);
    cout << ret << endl;
    return 0;
}