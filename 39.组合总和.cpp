// https://leetcode.cn/problems/combination-sum/description/
// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合
// 并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    int target;

    vector<vector<int>> combinationSum(vector<int> &candidates, int _target)
    {
        target = _target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0);
        return ret;
    }

    void dfs(vector<int> &nums, int sum)
    {
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        if (sum > target)
            return;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back())
                continue;
            path.push_back(nums[i]);
            dfs(nums, sum + nums[i]);
            path.pop_back();
        }
        return;
    }
};