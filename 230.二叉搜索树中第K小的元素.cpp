// https : // leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
// ����һ�������������ĸ��ڵ� root ����һ������ k ���������һ���㷨�������е� k ����СԪ�أ��� 1 ��ʼ��������
class Solution
{
public:
    int count;
    int ret;

    void dfs(TreeNode *root)
    {
        if (root == nullptr || count == 0)
            return;
        dfs(root->left);
        count--;
        if (count == 0)
        {
            ret = root->val;
            return;
        }
        dfs(root->right);
        return;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        count = k;
        ret = 0;
        dfs(root);
        return ret;
    }
};