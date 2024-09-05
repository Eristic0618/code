// https://leetcode.cn/problems/construct-string-from-binary-tree/description/
// 给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
// 空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
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