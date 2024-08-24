// https : // www.luogu.com.cn/problem/P9236#submit
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

int main()
{
    cin >> n;
    ll *arr = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll pow = 1, sum = 0;  
    for (int i = 0; i < 20; i++) //最多计算20个二进制位 
    {
        ll counti = 0, oddnum = 0, evenum = 0, range = 0; 
		//counti统计1的前缀和，oddnum统计奇数前缀和的个数
        //evenum统计偶数前缀和的个数，range统计有贡献区间个数 
        for (int j = 0; j < n; j++) //遍历n个整数 
        {
            if (arr[j] & 1) //按位与1后结果为1，说明最低位为1，否则为0 
                counti++; //更新前缀和 
            if (counti % 2 == 1) //前缀和为奇数
            {
                range += 1 + evenum; //更新有贡献区间个数 
                oddnum++; //奇数前缀和的个数+1 
            }
            else //前缀和为偶数 
            {
                range += oddnum; //更新有贡献区间个数 
                evenum++; //偶数前缀和的个数+1 
            }
            arr[j] >>= 1; //移位 
        }
        sum += range * pow; //计算位数对结果的贡献值 
        pow *= 2; //更新pow 
    }
    cout << sum;
    return 0;
}