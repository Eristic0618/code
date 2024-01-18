// 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
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