// https : // leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
class Solution
{
public:
    int count;
    int ret;

    void dfs(TreeNode *root)
    {
        if (root == nullptr || count == 0)
            return;
        dfs(root->left);
        count--;
        if (count == 0)
        {
            ret = root->val;
            return;
        }
        dfs(root->right);
        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        count = k;
        ret = 0;
        dfs(root);
        return ret;
    }
};