// https://leetcode.cn/problems/queries-on-a-permutation-with-key/description/
//  给定一个正整数数组 queries ，其取值范围在 1 到 m 之间。 请你根据以下规则按顺序处理所有 queries[i]（从 i=0 到 i=queries.length-1）：
//  首先，你有一个排列 P=[1,2,3,...,m]。
//  对于当前的 i ，找到 queries[i] 在排列 P 中的位置（从 0 开始索引），然后将它移到排列 P 的开头（即下标为 0 处）。
//  注意， queries[i] 的查询结果是 queries[i] 在 P 中移动前的位置。
//  返回一个数组，包含从给定  queries 中查询到的结果。
class Solution
{
public:
    int n, sz;
    vector<int> b;

    int count(int p)
    {
        int res = 0;
        while (p)
        {
            res += b[p];
            p -= p & (-p);
        }
        return res;
    }

    void add(int p, int x)
    {
        while (p <= sz)
        {
            b[p] += x;
            p += p & (-p);
        }
    }

    vector<int> processQueries(vector<int> &queries, int m)
    {
        n = queries.size();
        sz = m + n;
        b.resize(sz + 1);
        vector<int> ans;
        vector<int> index(m + 1);    // 存放P中元素在树状数组中的下标
        for (int i = 1; i <= m; i++) // 初始化
        {
            index[i] = n + i;
            add(n + i, 1); // 1为非空，0为空
        }
        for (int i = 0; i < n; i++)
        {
            int cur = index[queries[i]];
            add(cur, -1);              // 将原来位置置空
            ans.push_back(count(cur)); // 计算原位置前面有几个元素
            index[queries[i]] = n - i; // 更新新的位置
            add(n - i, 1);
        }
        return ans;
    }
};