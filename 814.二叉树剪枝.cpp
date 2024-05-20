// https://leetcode.cn/problems/binary-tree-pruning/
// ����������ĸ���� root ����������ÿ������ֵҪô�� 0 ��Ҫô�� 1 ��
// �����Ƴ������в����� 1 ��������ԭ��������
// �ڵ� node ������Ϊ node ����������� node �ĺ����
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