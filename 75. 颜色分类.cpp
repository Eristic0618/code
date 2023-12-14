// ����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
// ����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
// �����ڲ�ʹ�ÿ����õ� sort ����������½��������⡣
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int left = -1, right = n, i = 0, tmp = 0;
        while (i < right)
        {
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == 1)
                i++;
            else
                swap(nums[--right], nums[i]);
        }
    }
};