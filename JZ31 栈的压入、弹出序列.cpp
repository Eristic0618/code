// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&ru=/exam/oj
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
// 例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
// 1. 0<=pushV.length == popV.length <=1000
// 2. -1000<=pushV[i]<=1000
// 3. pushV 的所有数字均不相同
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int> &pushV, vector<int> &popV)
    {
        stack<int> st;
        int popi = 0;
        for (int i = 0; i < pushV.size(); i++)
        {
            st.push(pushV[i]);
            while (!st.empty() && st.top() == popV[popi])
            {
                st.pop();
                popi++;
            }
            if (!st.empty() && i == pushV.size() - 1)
                return false;
        }
        return true;
        ;
    }
};