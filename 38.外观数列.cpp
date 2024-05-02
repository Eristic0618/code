// https://leetcode.cn/problems/count-and-say/description/
// ����һ�������� n �����������еĵ� n �
// ��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
// ����Խ����������ɵݹ鹫ʽ����������ַ������У�
// countAndSay(1) = "1"
// countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����
// ǰ�������£�
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// ��һ�������� 1
// ����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
// ����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
// ����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
// ����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"
class Solution
{
public:
    string countAndSay(int n)
    {
        vector<int> num = {1};
        string ret;
        for (int i = 1; i < n; ++i)
        {
            int left = 0, right = 0;
            vector<int> tmp;
            int count = 0;
            while (right < num.size())
            {
                count = 0;
                while (right < num.size() && num[left] == num[right])
                    right++;
                count = right - left;
                tmp.push_back(count);
                tmp.push_back(num[left]);
                left = right;
            }
            num = tmp;
        }
        for (auto i : num)
        {
            ret += i + '0';
        }
        return ret;
    }
};