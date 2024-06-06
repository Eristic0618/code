// https://leetcode.cn/problems/binary-tree-paths/description/
// ����һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����
// Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
class Solution
{
public:
    vector<string> ret;

    void dfs(TreeNode *root, string path)
    {
        if (root == nullptr)
            return;
        if (!root->left && !root->right)
        {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root, "");
        return ret;
    }
};