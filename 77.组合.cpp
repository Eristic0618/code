// https://leetcode.cn/problems/combinations/description/
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 你可以按 任何顺序 返回答案。
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    int _n;
    int _k;

    vector<vector<int>> combine(int n, int k)
    {
        _n = n;
        _k = k;
        dfs(1);
        return ret;
    }

    void dfs(int pos)
    {
        if (path.size() == _k)
        {
            ret.push_back(path);
            return;
        }
        for (int i = pos; i <= _n; i++)
        {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    }
};