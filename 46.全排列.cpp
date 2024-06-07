// https://leetcode.cn/problems/permutations/description/
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
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