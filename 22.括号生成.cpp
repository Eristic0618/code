// https://leetcode.cn/problems/generate-parentheses/description/
// ���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
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