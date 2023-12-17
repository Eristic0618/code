// 给定一个长度为n的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
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
