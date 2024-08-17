// https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
// �����������Ե����� arr ��Ϊ ɽ������ ��
// arr.length >= 3
// ���� i��0 < i < arr.length - 1��ʹ�ã�
// arr[0] < arr[1] < ... arr[i-1] < arr[i]
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// ������������ɵ�ɽ������ arr ���������� arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] ���±� i ��
// �������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log(n)) �Ľ��������
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 1, right = arr.size() - 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1])
                left = mid;
            else if (arr[mid] < arr[mid - 1])
                right = mid - 1;
        }
        return left;
    }
};