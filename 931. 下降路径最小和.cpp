// https://leetcode.cn/problems/minimum-falling-path-sum/description/
// ����һ�� n x n �� ���� �������� matrix �������ҳ�������ͨ�� matrix ���½�·�� �� ��С�� ��
// �½�·�� ���Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�
// ����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ�У���λ�����·������ضԽ�������������ҵĵ�һ��Ԫ�أ���
// ������˵��λ�� (row, col) ����һ��Ԫ��Ӧ���� (row + 1, col - 1)��(row + 1, col) ���� (row + 1, col + 1) ��
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX)); // �࿪һ�����У���������Խ�磬Ҫ���������г�ʼ��ΪINT_MAX�������dp����д��Ϊ�˷�������֮���dp���ʼ��ΪINT_MAX
        for (int j = 0; j < n + 2; j++)
            dp[0][j] = 0; // ��dp��һ�г�ʼ��Ϊ0
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1]; // ѡ���������Ϸ���Сֵ����ԭʼ�����е�ֵ
        int min = INT_MAX;
        for (int i = 1; i <= n; i++)
            if (dp[n][i] < min)
                min = dp[n][i]; // �ҳ�dp�����һ�е���Сֵ��Ϊ��С·����
        return min;
    }
};