// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
// ����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
// ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�
// ���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
// ����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��
// Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ㡣
class Solution
{
public:
    int dfs(TreeNode *root, int n)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return n * 10 + root->val;
        int left = dfs(root->left, n * 10 + root->val);
        int right = dfs(root->right, n * 10 + root->val);
        return left + right;
    }

    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};