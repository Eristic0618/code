// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> ret;
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            while (n--)
            {
                for (int i = 0; i < q.front()->children.size(); i++)
                {
                    q.push(q.front()->children[i]);
                }
                temp.push_back(q.front()->val);
                q.pop();
            }
            ret.push_back(temp);
        }
        return ret;
    }
};