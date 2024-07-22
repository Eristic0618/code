// https://leetcode.cn/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/
// 给你一个正整数 k 。最初，你有一个数组 nums = [1] 。
// 你可以对数组执行以下 任意 操作 任意 次数（可能为零）：
// 选择数组中的任何一个元素，然后将它的值 增加 1 。
// 复制数组中的任何一个元素，然后将它附加到数组的末尾。
// 返回使得最终数组元素之 和 大于或等于 k 所需的 最少 操作次数。
class Solution
{
public:
    int ret;

    void dfs(int k, int sum, int max)
    {
        if (max + max * max < k)
        {
            max++;
            sum++;
            ret++;
            dfs(k, sum, max);
        }
        else
        {
            while (sum < k)
            {
                sum += max;
                ret++;
            }
            return;
        }
    }

    int minOperations(int k)
    {
        vector<int> nums(1, 1);
        dfs(k, 1, 1);
        return ret;
    }
};