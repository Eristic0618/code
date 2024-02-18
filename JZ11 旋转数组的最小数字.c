// ��һ������Ϊ n �ķǽ������飬����[1,2,3,4,5]������������ת������һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����һ����ת����
// ��������[3,4,5,1,2]������[4,5,1,2,3]�����ġ����ʣ���������һ����ת���飬�������е���Сֵ��
int minNumberInRotateArray(int *nums, int numsLen)
{
    // ���ַ�
    int left = 0, right = numsLen - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid == 0 && nums[mid] < nums[numsLen - 1])
            return nums[mid];
        if (nums[mid + 1] < nums[mid])
            return nums[mid + 1];
        if (nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[mid] < nums[left])
            right = mid;
        if (nums[mid] > nums[right])
            left = mid;
        else
            right--;
    }
    return -1;
}