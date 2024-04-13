// https://leetcode.cn/problems/first-unique-character-in-a-string/description/
// ����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int count[26] = {0};
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};