// https://www.nowcoder.com/share/jump/8993698061708605588253
// ����һ������Ϊn������nums�������ҵ���ֵ��������������������ܰ��������ֵ������������£������κ�һ������λ�ü��ɡ�
// 1.��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء��ϸ���ڼ������е���
// 2.���� nums[-1] = nums[n] = ?��
// 3.����������Ч�� i ���� nums[i] != nums[i + 1]
// 4.�����ʹ��O(logN)��ʱ�临�Ӷ�ʵ�ִ�������
int findPeakElement(int *nums, int numsLen)
{
    if (numsLen == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    else if (nums[numsLen - 2] < nums[numsLen - 1])
        return numsLen - 1;
    int left = 0, mid = 1, right = 2;
    while (right < numsLen)
    {
        if (nums[mid] > nums[left] && nums[mid] > nums[right])
            return mid;
        else
        {
            left++;
            mid++;
            right++;
        }
    }
    return -1;
}