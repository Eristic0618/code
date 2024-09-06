// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// 时间复杂度:O(N^2)
//  class Solution {
//  public:
//      bool NodeSearch(TreeNode* root, TreeNode* aim)
//      {
//          if(root == nullptr)
//              return false;
//          if(root == aim)
//              return true;
//          return NodeSearch(root->left, aim) || NodeSearch(root->right, aim);
//      }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == p || root == q)
//             return root;

//         bool pInleft = NodeSearch(root->left, p);
//         bool pInright = !pInleft;
//         bool qInleft = NodeSearch(root->left, q);
//         bool qInright = !qInleft;
//         if(pInleft && qInright || pInright && qInleft)
//             return root;
//         else if(pInleft && qInleft)
//             return lowestCommonAncestor(root->left, p, q);
//         else
//             return lowestCommonAncestor(root->right, p, q);
//     }
// };

// O(N)
class Solution
{
public:
    bool PathSearch(TreeNode *root, TreeNode *aim, stack<TreeNode *> &path)
    {
        if (root == nullptr)
            return false;
        path.push(root);
        if (root == aim)
            return true;
        if (PathSearch(root->left, aim, path))
            return true;
        if (PathSearch(root->right, aim, path))
            return true;
        path.pop();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> pPath, qPath;
        PathSearch(root, p, pPath);
        PathSearch(root, q, qPath);
        int sizep = pPath.size(), sizeq = qPath.size();
        int diff = abs(sizep - sizeq);
        while (diff--)
        {
            if (sizep > sizeq)
                pPath.pop();
            else
                qPath.pop();
        }
        while (!pPath.empty())
        {
            if (pPath.top() == qPath.top())
                return pPath.top();
            pPath.pop();
            qPath.pop();
        }
        return nullptr;
    }
};