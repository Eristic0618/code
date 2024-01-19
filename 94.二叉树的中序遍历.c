// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
void InOrder(struct TreeNode *root, int *arr, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, arr, returnSize);
    arr[(*returnSize)++] = root->val;
    InOrder(root->right, arr, returnSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    InOrder(root, arr, returnSize);
    return arr;
}