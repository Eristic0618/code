//https://www.acwing.com/problem/content/description/837/
#include <iostream>
using namespace std;

const int N = 100010; //总字符个数不超过1e5

int n;
int son[N][26]; //Trie树
int count[N], idx; //count[i]用于标记编号为i的节点是几个字符串的结尾, idx是Trie树中每个节点的编号

void insert(char* str) //插入字符串
{
    int q = 0; //从根节点开始
    for(int i = 0; str[i];i++) //遍历字符串
    {
        int u = str[i] - 'a'; //字符映射为下标
        if(!son[q][u]) son[q][u] = ++idx; //增加新节点
        q = son[q][u]; //获取下一个节点的编号
    }
    count[q]++; //q号节点作为字符串结尾的个数+1
}

int query(char* str) //查询字符串
{
    int q = 0;
    for(int i = 0; str[i];i++)
    {
        int u = str[i] - 'a';
        if(!son[q][u]) return 0; //该字符节点不存在
        q = son[q][u];
    }
    return count[q]; //返回字符串出现的次数
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        char c;
        char str[N];
        cin >> c >> str;
        if(c == 'I') insert(str);
        else cout << query(str) << endl;;
    }
    return 0;
}