// ����һ�ö������ĸ��ڵ� root ��������ڵ�ֵ�� ������� ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void PastOrder(struct TreeNode *root, int *arr, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }
    PastOrder(root->left, arr, returnSize);
    PastOrder(root->right, arr, returnSize);
    arr[(*returnSize)++] = root->val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    PastOrder(root, arr, returnSize);
    return arr;
}