// ����һ���������� nums ������������ �����±� ��
// ���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//  ��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//  ��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� -1 ��
int pivotIndex(int *nums, int numsSize)
{
    int *leftsum = (int *)malloc(sizeof(int) * numsSize);
    memset(leftsum, 0, sizeof(int) * numsSize);
    int *rightsum = (int *)malloc(sizeof(int) * numsSize);
    memset(rightsum, 0, sizeof(int) * numsSize);
    int index = -1;
    for (int i = 1; i < numsSize; i++)
    {
        leftsum[i] = leftsum[i - 1] + nums[i - 1];
    }
    for (int i = numsSize - 2; i >= 0; i--)
    {
        rightsum[i] = rightsum[i + 1] + nums[i + 1];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (leftsum[i] == rightsum[i])
        {
            index = i;
            break;
        }
    }
    return index;
}