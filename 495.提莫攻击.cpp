// https://leetcode.cn/problems/teemo-attacking/
// �ڡ�Ӣ�����ˡ��������У���һ���� ����Ī�� ��Ӣ�ۡ����Ĺ��������õз�Ӣ�۰�ϣ������ע���������֣������ж�״̬��
// ����Ī������ϣ����ϣ���ж�״̬���ó��� duration �롣
// ��ʽ�ؽ�����Ī�� t ���𹥻���ζ�Ű�ϣ��ʱ������ [t, t + duration - 1]���� t �� t + duration - 1�������ж�״̬��
// �����Ī���ж�Ӱ����� ǰ �ٴι������ж�״̬��ʱ������ ���� �����µĹ���֮���ж�Ӱ�콫���� duration ��������
// ����һ�� �ǵݼ� ���������� timeSeries ������ timeSeries[i] ��ʾ��Ī�� timeSeries[i] ��ʱ�԰�ϣ���𹥻����Լ�һ����ʾ�ж�����ʱ������� duration ��
// ���ذ�ϣ�����ж�״̬�� �� ������
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int ret = 0;
        for (size_t i = 0; i < timeSeries.size() - 1; ++i)
        {
            int d = timeSeries[i + 1] - timeSeries[i];
            if (d >= duration)
                ret += duration;
            else
                ret += d;
        }
        ret += duration;
        return ret;
    }
};
