// ����һ�������� root �������������ȡ�
// �������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}