// https://leetcode.cn/problems/permutations-ii/description/
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9];

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ret;
    }

    void dfs(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!check[i] && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};