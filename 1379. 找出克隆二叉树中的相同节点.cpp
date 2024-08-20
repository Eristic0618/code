// https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/?envType=daily-question&envId=2024-04-03
// �������ö�������ԭʼ�� original �Ϳ�¡�� cloned���Լ�һ��λ��ԭʼ�� original �е�Ŀ��ڵ� target��
// ���У���¡�� cloned ��ԭʼ�� original ��һ�� ���� ��
// ���ҳ����� cloned �У��� target ��ͬ �Ľڵ㣬�����ضԸýڵ�����ã��� C/C++ ����ָ��������з��� �ڵ�ָ�룬�������Է��ؽڵ㱾����
// ע�⣺�� ���� �����ö��������Լ� target �ڵ���и��ġ�ֻ�� ���ضԿ�¡�� cloned �����еĽڵ�����á�
// ������ȱ���
class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(cloned);
        while (!q.empty())
        {
            if (q.front()->val == target->val)
                return q.front();
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        return nullptr;
    }
};