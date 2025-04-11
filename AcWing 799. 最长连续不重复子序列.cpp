//https://www.acwing.com/problem/content/801/
#include <bits/stdc++.h>
using namespace std;

#define N 1000010

int n, len;
int a[N];
int hs[N]; //哈希表记录区间内元素数量

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0; //双指针
    while(r < n)
    {
        hs[a[r]]++;
        while(hs[a[r]] > 1) //有重复元素
        {
            hs[a[l]]--;
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    cout << len << endl;
    return 0;
}