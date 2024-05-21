// https://leetcode.cn/problems/validate-binary-search-tree/description/
// ����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
// ��Ч �����������������£�
// �ڵ��������ֻ���� С�� ��ǰ�ڵ������
// �ڵ��������ֻ���� ���� ��ǰ�ڵ������
// �������������������������Ҳ�Ƕ�����������
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