// �������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
// ������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������

bool isSameTree(struct TreeNode *p, struct TreeNode *q) // cv��100.��ͬ����,�ж�������subroot�Ƿ���ͬ
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

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
    if (root == NULL)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}