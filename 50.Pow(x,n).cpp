// https://leetcode.cn/problems/powx-n/
// 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
class Solution
{
public:
    double Pow(double x, int n)
    {
        if (n == 0)
            return 1;
        double tmp = myPow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }

    double myPow(double x, int n)
    {
        if (n < 0)
            return 1 / pow(x, -(long long)(n));
        else
            return pow(x, n);
    }
};