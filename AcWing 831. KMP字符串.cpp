// https://www.acwing.com/activity/content/problem/content/869/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 100010;
const int M = 1000010;

int ne[N];
int n, m;

void buildNext(string &p) //��дnext����
{
    int front = 0;
    int i = 1;
    while (i < n)
    {
        if (p[i] == p[front]) //�����ַ���ͬǰ��׺�䳤
        {
            front++;
            ne[i] = front;
            i++;
        }
        else //�ַ���ƥ�䣬�޷����ɸ����Ĺ�ͬǰ��׺
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
        if (s[i] == p[j]) //�ַ�ƥ�䣬ָ������ƶ�
            i++, j++;
        else if (j > 0) //�ַ���ƥ�䣬����ǰһ��λ�õ�next�ж��������ٸ��ַ�
            j = ne[j - 1];
        else //�Ӵ���һ���ַ��Ͳ�ƥ��
            i++;
        if (j == n) //�ַ���ƥ�䣬λ������ans
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