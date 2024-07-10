// https://leetcode.cn/problems/min-stack/description/
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
// 实现 MinStack 类:
// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素
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