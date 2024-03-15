// https://www.nowcoder.com/share/jump/8993698061708567395970
// ����һ���������� numbers ��һ��Ŀ��ֵ target�������������ҳ���������������Ŀ��ֵ�������±꣬���ص��±갴�������С�
// ��ע�����ص������±��1��ʼ���𣬱�֤targetһ����������������2��������ӵõ���
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int *twoSum(int *numbers, int numbersLen, int target, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);
    *returnSize = 2;
    int *hash[2]; // ��������ԭ�±�
    hash[0] = (int *)malloc(sizeof(int) * numbersLen);
    hash[1] = (int *)malloc(sizeof(int) * numbersLen);
    for (int i = 0; i < numbersLen; i++)
    {
        hash[0][i] = numbers[i];
        hash[1][i] = i + 1;
    }
    qsort(numbers, numbersLen, sizeof(int), cmp); // ��������
    for (int i = 0; i < numbersLen; i++)          // �������� O(N)
    {
        int diff = target - numbers[i]; // ���ÿ������target�Ĳ�ֵ
        int begin = 0, end = numbersLen - 1;
        bool flag = false;
        while (begin <= end) // ����Ѱ�Ҳ�ֵ O(logn)
        {
            int mid = (begin + end) / 2;
            if (mid == i) // ��ʱ��Ҫ������������ѭ��
            {
                begin += 1;
                continue;
            }
            if (numbers[mid] == diff) // �ҵ�
            {
                for (int j = 0; j < numbersLen; j++)
                {
                    if (hash[0][j] == numbers[i] && ret[0] == 0) // ��ֹ�ظ���ֵ
                    {
                        ret[0] = hash[1][j];
                    }
                    else if (hash[0][j] == numbers[mid] && hash[1][j] != ret[0])
                    {
                        ret[1] = hash[1][j];
                    }
                }
                flag = true;
                break; // ����ѭ��
            }
            else if (numbers[mid] < diff)
            {
                begin = mid + 1;
            }
            else if (numbers[mid] > diff)
            {
                end = mid - 1;
            }
        }
        if (flag)
            break;
    }
    qsort(ret, 2, sizeof(int), cmp); // ���Է�����������
    return ret;
}