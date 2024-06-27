// https://leetcode.cn/problems/fibonacci-number/description/
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
class Solution
{
public:
    int memo[31];

    int fib(int n)
    {
        memset(memo, -1, sizeof(memo));
        return dfs(n);
    }

    int dfs(int n)
    {
        if (memo[n] != -1)
            return memo[n];
        if (n == 0 || n == 1)
        {
            memo[n] = n;
            return n;
        }
        return dfs(n - 1) + dfs(n - 2);
    }
};