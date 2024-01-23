// ���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
// ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
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