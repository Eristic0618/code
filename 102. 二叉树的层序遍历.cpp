// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> ret;
        q.push(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            while (n--)
            {
                TreeNode *front = q.front();
                temp.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                q.pop();
            }
            ret.push_back(temp);
        }
        return ret;
    }
};