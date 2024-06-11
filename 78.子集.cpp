// https://leetcode.cn/problems/subsets/description/
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
// 解法1
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
// 解法2
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