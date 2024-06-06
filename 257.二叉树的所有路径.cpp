// https://leetcode.cn/problems/binary-tree-paths/description/
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
// 叶子节点 是指没有子节点的节点。
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