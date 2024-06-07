// https://leetcode.cn/problems/permutations/description/
// ����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];

    void dfs(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!check[i])
            {
                path.push_back(nums[i]);
                check[i] = 1;
                if (path.size() == nums.size())
                {
                    ret.push_back(path);
                    path.pop_back();
                    check[i] = 0;
                    return;
                }
                dfs(nums);
                path.pop_back();
                check[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums);
        return ret;
    }
};