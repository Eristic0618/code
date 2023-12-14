// ����һ���ַ��� s ������ͳ�Ʋ���������ַ����� �����Ӵ� ����Ŀ��
// �����ַ��� �����Ŷ��͵�������һ�����ַ�����
// ���ַ��� ���ַ����е��������ַ���ɵ�һ�����С�
// ���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j || i + 1 == j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] == 1)
                    {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};