// https://leetcode.cn/problems/min-stack/description/
// ���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
// ʵ�� MinStack ��:
// MinStack() ��ʼ����ջ����
// void push(int val) ��Ԫ��val�����ջ��
// void pop() ɾ����ջ������Ԫ�ء�
// int top() ��ȡ��ջ������Ԫ�ء�
// int getMin() ��ȡ��ջ�е���СԪ��
class MinStack
{
public:
    MinStack()
    {}

    void push(int val)
    {
        _st.push(val);
        if (_minst.empty() || _minst.top() >= val)
            _minst.push(val);
    }

    void pop()
    {
        if (_minst.top() == _st.top())
            _minst.pop();
        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minst.top();
    }

private:
    stack<int> _st;
    stack<int> _minst;
};