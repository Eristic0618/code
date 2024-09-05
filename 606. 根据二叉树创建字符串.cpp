// https://leetcode.cn/problems/construct-string-from-binary-tree/description/
// ����������ĸ��ڵ� root ���������ǰ������ķ�ʽ����������ת��Ϊһ�������ź�������ɵ��ַ��������ع�������ַ�����
// �սڵ�ʹ��һ�Կ����Ŷ� "()" ��ʾ��ת������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        string ret;
        ret += to_string(root->val);

        if (root->left || root->right)
        {
            ret += "(";
            ret += tree2str(root->left);
            ret += ")";
        }

        if (root->right)
        {
            ret += "(";
            ret += tree2str(root->right);
            ret += ")";
        }
        return ret;
    }
};