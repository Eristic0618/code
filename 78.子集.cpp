// https://leetcode.cn/problems/subsets/description/
// ����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
// �⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
// �ⷨ1
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ret;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            ret.push_back(path);
            return;
        }
        dfs(nums, i + 1);
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
        return;
    }
};
// �ⷨ2
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ret;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int> &nums, int pos)
    {
        ret.push_back(path);
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};