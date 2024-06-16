// https://leetcode.cn/problems/generate-parentheses/description/
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
class Solution
{
public:
    vector<string> ret;
    string path;
    int countleft;
    int countright;

    vector<string> generateParenthesis(int n)
    {
        dfs(n);
        return ret;
    }

    void dfs(int n)
    {
        if (countleft > n || countright > n || countright > countleft)
            return;
        if (countleft == n && countright == n)
        {
            ret.push_back(path);
            return;
        }
        path += '(';
        countleft++;
        dfs(n);
        path.erase(path.size() - 1);
        countleft--;
        path += ')';
        countright++;
        dfs(n);
        path.erase(path.size() - 1);
        countright--;
        return;
    }
};