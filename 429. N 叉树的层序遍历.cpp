// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
// ����һ�� N ������������ڵ�ֵ�Ĳ�����������������ң�����������
// �������л��������ò��������ÿ���ӽڵ㶼�� null ֵ�ָ����μ�ʾ������
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