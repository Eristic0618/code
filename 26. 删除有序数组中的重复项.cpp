// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
//  ����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//  Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����
//  ���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����
//  �������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
//  ���� k ��
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0, r = 0;
        while (r < nums.size())
        {
            if (nums[l] != nums[r])
                nums[++l] = nums[r];
            r++;
        }
        return l + 1;
    }
};