// https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/
// ����һ�� ���������� �ĸ��������������������
// Ҷ�ӽڵ� ҪôֵΪ 0 ҪôֵΪ 1 ������ 0 ��ʾ False ��1 ��ʾ True ��
// ��Ҷ�ӽڵ� ҪôֵΪ 2 ҪôֵΪ 3 ������ 2 ��ʾ�߼��� OR ��3 ��ʾ�߼��� AND ��
// ���� һ���ڵ��ֵ��ʽ���£�
// ����ڵ��Ǹ�Ҷ�ӽڵ㣬��ô�ڵ�� ֵ Ϊ�������� True ���� False ��
// ���򣬼��� �������ӵĽڵ�ֵ��Ȼ�󽫸ýڵ�����������������ֵ���� ���� ��
// ���ظ��ڵ� root �Ĳ�������ֵ��
// ���������� ��ÿ���ڵ��� 0 ������ 2 �����ӵĶ�������
// Ҷ�ӽڵ� ��û�к��ӵĽڵ㡣
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->val == 0 || root->val == 1)
            return root->val;
        if (root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};