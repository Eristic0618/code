// �������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
// ����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ��
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL || q == NULL)
    {
        if (p == NULL && q == NULL)
            return true;
        else
            return false;
    }
    if (p->val == q->val)
    {
        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
            return false;
        else
            return true;
    }
    else
        return false;
}