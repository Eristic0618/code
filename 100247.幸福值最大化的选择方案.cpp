// https://leetcode.cn/problems/maximize-happiness-of-selected-children/description/
// 给你一个长度为 n 的数组 happiness ，以及一个 正整数 k 。
// n 个孩子站成一队，其中第 i 个孩子的 幸福值 是 happiness[i] 。你计划组织 k 轮筛选从这 n 个孩子中选出 k 个孩子。
// 在每一轮选择一个孩子时，所有 尚未 被选中的孩子的 幸福值 将减少 1 。注意，幸福值 不能 变成负数，且只有在它是正数的情况下才会减少。
// 选择 k 个孩子，并使你选中的孩子幸福值之和最大，返回你能够得到的 最大值 。
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long happysum = 0;
        int sub = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; ++i)
        {
            if (happiness[i] - sub > 0)
            {
                happysum += happiness[i] - sub;
            }
            else
            {
                happysum += 0;
            }
            sub++;
        }
        return happysum;
    }
};