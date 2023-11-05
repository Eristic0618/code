#include <stdio.h>

int bin_search(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            left++;
            right = mid;
        }
        else if (arr[mid] < key)
        {
            right--;
            left = mid;
        }
    }
    if (left > right)
    {
        return -1;
    }
}

int main()
{
    int n;
    printf("�����������С:");
    scanf("%d", &n);
    int test[n];
    printf("��������������:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &test[i]);
    }
    int x;
    printf("������Ҫ���ҵ�����:");
    scanf("%d", &x);
    int ret = bin_search(test, 0, n - 1, x);
    printf("%d", ret);
    return 0;
}