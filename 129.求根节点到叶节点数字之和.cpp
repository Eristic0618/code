// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。
class Solution
{
public:
    int dfs(TreeNode *root, int n)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return n * 10 + root->val;
        int left = dfs(root->left, n * 10 + root->val);
        int right = dfs(root->right, n * 10 + root->val);
        return left + right;
    }

    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};