// 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
// 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode *root)
{
    if (root == NULL)
        return true;
    bool left, right;
    if (root->left != NULL && root->val != root->left->val)
        return false;
    else
        left = isUnivalTree(root->left);
    if (root->right != NULL && root->val != root->right->val)
        return false;
    else
        right = isUnivalTree(root->right);
    return left && right;
}