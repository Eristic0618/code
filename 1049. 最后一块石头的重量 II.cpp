// https://leetcode.cn/problems/last-stone-weight-ii/description/
// 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

// 思路：
// 两个石头相撞，结果可能是a-b,也可能是b-a
// 所以最后的结果中有的数前面是减号有的是加号
// 因此可以分为正数部分和负数部分，当两部分尽可能接近时，也就是接近数组和/2时，相减得到最小值
// 转化为01背包问题：挑选数使得尽可能接近数组和/2
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto i : stones)
            sum += i;
        int val = sum / 2;
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(val + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= val; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        return sum - dp[n][val] * 2;
    }
};

// 优化：滚动数组
//  class Solution {
//  public:
//      int lastStoneWeightII(vector<int>& stones) {
//          int sum = 0;
//          for(auto i : stones)
//              sum += i;
//          int val = sum / 2;
//          int n = stones.size();
//          vector<int> dp(val+1);
//          for(int i = 1;i <= n;i++)
//              for(int j = val;j >= stones[i-1];j--)
//                  dp[j] = max(dp[j], dp[j - stones[i-1]] + stones[i-1]);
//          return sum - dp[val] * 2;
//      }
//  };