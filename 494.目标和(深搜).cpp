// https://leetcode.cn/problems/target-sum/description/
// 给你一个非负整数数组 nums 和一个整数 target 。
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
class Solution
{
public:
    int sum;
    int count;
    int target;

    int findTargetSumWays(vector<int> &nums, int _target)
    {
        target = _target;
        dfs(nums, 0);
        return count;
    }

    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            if (sum == target)
                count++;
            return;
        }
        sum += nums[i];
        dfs(nums, i + 1);
        sum -= nums[i] * 2;
        dfs(nums, i + 1);
        sum += nums[i];
        return;
    }
};