// https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/
// ����һ���ַ��� s �����ҳ�����ÿ���ַ����������ε�����ַ����������ظ����ַ����� ��� ���ȡ�
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        vector<int> hash(26);
        int prev = 0, cur = 0;
        int ret = 1;
        while (cur < s.size())
        {
            hash[s[cur] - 'a']++;
            if (hash[s[cur] - 'a'] == 3)
            {
                while (s[prev] != s[cur])
                {
                    hash[s[prev] - 'a']--;
                    prev++;
                }
                hash[s[prev] - 'a']--;
                prev++;
            }
            ret = max(ret, cur - prev + 1);
            cur++;
        }
        return ret;
    }
};