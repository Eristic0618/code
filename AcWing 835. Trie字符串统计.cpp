// https://www.acwing.com/problem/content/837/
#include <iostream>
using namespace std;

const int N = 100010;

int n;
int son[N][26], count[N], idx;

void insert(char *str)
{
    int q = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[q][u])
            son[q][u] = ++idx;
        q = son[q][u];
    }
    count[q]++;
}

int query(char *str)
{
    int q = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[q][u])
            return 0;
        q = son[q][u];
    }
    return count[q];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        char str[N];
        cin >> c >> str;
        if (c == 'I')
            insert(str);
        else
            cout << query(str) << endl;
        ;
    }
    return 0;
}