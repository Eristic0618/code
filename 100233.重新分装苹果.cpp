// https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
// ����һ������Ϊ n ������ apple ����һ������Ϊ m ������ capacity ��
// һ���� n �����������е� i ��������װ�� apple[i] ��ƻ����ͬʱ������ m �����ӣ��� i �����ӵ�����Ϊ capacity[i] ��ƻ����
// ����ѡ��һЩ���������� n �������е�ƻ�����·�װ�������У���������Ҫѡ������ӵ� ��С ������
// ע�⣬ͬһ�������е�ƻ�����Է�װ����ͬ�������С�
class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int applenum = 0;
        for (size_t i = 0; i < apple.size(); i++)
        {
            applenum += apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int count = 0;
        int i = 0;
        while (applenum > 0)
        {
            applenum -= capacity[i];
            i++;
            count++;
        }
        return count;
    }
};