// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// ����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��
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