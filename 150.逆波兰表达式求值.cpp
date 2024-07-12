// https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
// ����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��
// �������ñ��ʽ������һ����ʾ���ʽֵ��������
// ע�⣺
// ��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
// ÿ����������������󣩶�������һ������������һ�����ʽ��
// ��������֮��ĳ������� ����ض� ��
// ���ʽ�в����������㡣
// ������һ�������沨����ʾ����ʾ���������ʽ��
// �𰸼������м������������ 32 λ ������ʾ��
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "/" || str == "*")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};