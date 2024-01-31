// 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
// 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

bool isSameTree(struct TreeNode *p, struct TreeNode *q) // cv了100.相同的树,判断子树与subroot是否相同
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