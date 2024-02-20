// ����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���
int GetNumberOfK(int *nums, int numsLen, int k)
{
    int left = 0, right = numsLen - 1;
    int mid = 0;
    bool flag = false;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < k)
            left = mid + 1;
        else if (nums[mid] > k)
            right = mid - 1;
        else if (nums[mid] == k)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
        return 0;
    int prev = mid, cur = mid;
    while (nums[prev] == k || nums[cur] == k)
    {
        if (nums[prev] == k)
            prev--;
        if (nums[cur] == k)
            cur++;
    }
    return cur - prev - 1;
}