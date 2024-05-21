// https://leetcode.cn/problems/validate-binary-search-tree/description/
// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
// 有效 二叉搜索树定义如下：
// 节点的左子树只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
class Solution
{
public:
    long prev = LONG_MIN;

    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        bool left = isValidBST(root->left);
        if (left == false)
            return false;
        if (prev < root->val)
            prev = root->val;
        else
            return false;
        bool right = isValidBST(root->right);
        return left && right;
    }
};