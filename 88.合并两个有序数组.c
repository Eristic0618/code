// ���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
// ���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
// ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n
// ����ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (n == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }
    int n1 = m - 1;
    int n2 = n - 1;
    int num = m + n - 1;
    while (n1 >= 0 && n2 >= 0)
    {
        if (nums1[n1] > nums2[n2])
        {
            nums1[num--] = nums1[n1--];
        }
        else
        {
            nums1[num--] = nums2[n2--];
        }
    }
    if (n2 >= 0)
    {
        for (int i = 0; i <= n2; i++)
        {
            nums1[i] = nums2[i];
        }
    }
}
