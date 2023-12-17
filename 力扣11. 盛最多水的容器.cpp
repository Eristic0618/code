// ����һ������Ϊn���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
// �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
// �����������Դ�������ˮ����
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return ans;
    }
};
