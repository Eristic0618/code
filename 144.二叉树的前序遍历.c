// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
void PreOrder(struct TreeNode *root, int *arr, int *returnSize)
{
	if (root == NULL)
	{
		return;
	}
	arr[(*returnSize)++] = root->val;
	PreOrder(root->left, arr, returnSize);
	PreOrder(root->right, arr, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
	int *arr = (int *)malloc(sizeof(int) * 1000);
	*returnSize = 0;
	PreOrder(root, arr, returnSize);
	return arr;
}