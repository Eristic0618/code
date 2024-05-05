// https://leetcode.cn/problems/hanota-lcci/description/
// 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
// (1) 每次只能移动一个盘子;
// (2) 盘子只能从柱子顶端滑出移到下一根柱子;
// (3) 盘子只能叠在比它大的盘子上。
class Solution
{
public:
    void dfs(vector<int> &x, vector<int> &y, vector<int> &z, size_t n)
    {
        if (n == 1)
        {
            z.push_back(x.back());
            x.pop_back();
            return;
        }
        dfs(x, z, y, n - 1);
        z.push_back(x.back());
        x.pop_back();
        dfs(y, x, z, n - 1);
    }

    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        dfs(A, B, C, A.size());
    }
};