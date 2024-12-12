// ����һ���ַ��� s���ҵ� s ����� �����Ӵ�
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;
        int len = s.size();
        vector<vector<bool>> v(len, vector<bool>(len));
        // ��̬�滮��v[i][j] = true->��i��j���Ӵ��ǻ���
        for (int i = 0; i < len; i++) // ��ʼ��
            v[i][i] = true;
        for (int sl = 2; sl <= len; sl++) // �������Ӵ�����
        {
            for (int i = 0; i <= len - sl; i++) // i��ǰ�����ƶ�
            {
                if (s[i] == s[i + sl - 1]) // �ַ�ƥ��
                {
                    if (i + 1 == i + sl - 1) // ���i��j������ֱ���ǻ���
                        v[i][i + sl - 1] = true;
                    else if (v[i + 1][i + sl - 1 - 1]) // i��j�����ڣ��ж�i+1��j-1�Ƿ��ǻ���
                        v[i][i + sl - 1] = true;
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (v[i][j] && (r - l + 1 < j - i + 1)) // ��������Ӵ�
                    l = i, r = j;
            }
        }
        string ans = s.substr(l, r - l + 1);
        return ans;
    }
};