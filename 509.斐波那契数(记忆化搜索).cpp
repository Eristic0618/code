// https://leetcode.cn/problems/fibonacci-number/description/
// 쳲������� ��ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲��������� ���������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�
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