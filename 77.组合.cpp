// https://leetcode.cn/problems/combinations/description/
// ������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
// ����԰� �κ�˳�� ���ش𰸡�
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