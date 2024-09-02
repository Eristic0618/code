// https://leetcode.cn/problems/last-stone-weight-ii/description/
// ��һ��ʯͷ������������ stones ��ʾ������ stones[i] ��ʾ�� i ��ʯͷ��������
// ÿһ�غϣ�����ѡ����������ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�
// ��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
// ��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
// ������ֻ��ʣ��һ�� ʯͷ�����ش�ʯͷ ��С�Ŀ������� �����û��ʯͷʣ�£��ͷ��� 0��

// ˼·��
// ����ʯͷ��ײ�����������a-b,Ҳ������b-a
// �������Ľ�����е���ǰ���Ǽ����е��ǼӺ�
// ��˿��Է�Ϊ�������ֺ͸������֣��������־����ܽӽ�ʱ��Ҳ���ǽӽ������/2ʱ������õ���Сֵ
// ת��Ϊ01�������⣺��ѡ��ʹ�þ����ܽӽ������/2
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto i : stones)
            sum += i;
        int val = sum / 2;
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(val + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= val; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        return sum - dp[n][val] * 2;
    }
};

// �Ż�����������
//  class Solution {
//  public:
//      int lastStoneWeightII(vector<int>& stones) {
//          int sum = 0;
//          for(auto i : stones)
//              sum += i;
//          int val = sum / 2;
//          int n = stones.size();
//          vector<int> dp(val+1);
//          for(int i = 1;i <= n;i++)
//              for(int j = val;j >= stones[i-1];j--)
//                  dp[j] = max(dp[j], dp[j - stones[i-1]] + stones[i-1]);
//          return sum - dp[val] * 2;
//      }
//  };