// https://leetcode.cn/problems/pascals-triangle/description/
// ����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> q(numRows);
        for (int i = 0; i < numRows; i++)
        {
            q[i].resize(i + 1);
            q[i][0] = q[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                q[i][j] = q[i - 1][j - 1] + q[i - 1][j];
            }
        }
        return q;
    }
};