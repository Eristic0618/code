// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&ru=/exam/oj
// ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
// ��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
// 1. 0<=pushV.length == popV.length <=1000
// 2. -1000<=pushV[i]<=1000
// 3. pushV ���������־�����ͬ
class Solution
{
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
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