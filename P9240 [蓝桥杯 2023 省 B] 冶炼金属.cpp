// https : // www.luogu.com.cn/problem/P9240
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 二分查找
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> note(N, vector<int>(2));
    int left = 1, right = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> note[i][0] >> note[i][1];
        right = max(right, note[i][0]);
    }
    int tmp = right;     // 保存一下right的值
    while (left < right) // 查找左端点
    {
        int mid = left + (right - left) / 2;
        int flag = 1; // 检测是否所有记录都符合
        for (int i = 0; i < N; i++)
        {
            if (note[i][0] / mid > note[i][1]) // 转换率低了
            {
                left = mid + 1;
                flag = 0;
            }
            else if (note[i][0] / mid < note[i][1]) // 转换率高了
            {
                right = mid; // right不能等于mid-1，否则有跳出正确区间的风险
                flag = 0;
            }
        }
        if (flag) // 如果全部符合说明mid在正确的区间内，但是不一定是左端点
            right = mid;
    }
    // 当循环结束说明left和right重叠，此时即为左端点
    int begin = left;    // 保存左端点
    right = tmp;         // 重置right值
    while (left < right) // 查找右端点，需要修改一些细节
    {
        int mid = left + (right - left + 1) / 2; // 当区间元素为偶数个时，取右边的中点
        int flag = 1;
        for (int i = 0; i < N; i++)
        {
            if (note[i][0] / mid < note[i][1])
            {
                right = mid - 1;
                flag = 0;
            }
        }
        if (flag)
            left = mid; // left不能等于mid+1，否则有跳出正确区间的风险
    }
    // 当循环结束说明left和right重叠，此时即为右端点
    int end = right; // 保存右端点
    cout << begin << " " << end;
    return 0;
}