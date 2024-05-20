// https://leetcode.cn/problems/binary-tree-pruning/
// 给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
// 返回移除了所有不包含 1 的子树的原二叉树。
// 节点 node 的子树为 node 本身加上所有 node 的后代。
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root->left)
            root->left = pruneTree(root->left);
        if (root->right)
            root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
        {
            delete root;
            return nullptr;
        }
        else
            return root;
    }
};