// https://www.acwing.com/activity/content/problem/content/869/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 100010;
const int M = 1000010;

int ne[N];
int n, m;

void buildNext(string &p) //填写next数组
{
    int front = 0;
    int i = 1;
    while (i < n)
    {
        if (p[i] == p[front]) //加入字符后共同前后缀变长
        {
            front++;
            ne[i] = front;
            i++;
        }
        else //字符不匹配，无法构成更长的共同前后缀
        {
            if (front == 0)
            {
                ne[i] = 0;
                i++;
            }
            else
                front = ne[front - 1];
        }
    }
}

int main()
{
    string p;
    string s;
    cin >> n >> p >> m >> s;
    buildNext(p);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m)
    {
        if (s[i] == p[j]) //字符匹配，指针向后移动
            i++, j++;
        else if (j > 0) //字符不匹配，根据前一个位置的next判断跳过多少个字符
            j = ne[j - 1];
        else //子串第一个字符就不匹配
            i++;
        if (j == n) //字符串匹配，位置填入ans
        {
            ans.push_back(i - j);
            j = ne[j - 1];
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}