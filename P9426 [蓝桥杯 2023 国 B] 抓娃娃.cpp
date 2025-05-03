//https://www.luogu.com.cn/problem/P9426
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

#define N 1000010

int n, m, minl = 1e8, maxr;
vector<pair<int, int>> v;
int f[N]; //前缀和, f[i]代表1-i之间能框住的区间数
unordered_map<int, int> lmids; //记录线段左中点
unordered_map<int, int> rmids; //记录线段右中点
//如果线段长度为偶数，只有i是线段右中点才算框住一半以上的长度，所以在预处理前缀和时对于偶数长度线段要按照右中点

template<class T>
class cmp {
public:
    bool operator()(const T& a, const T& b)
    {
        return a.second < b.second;
    }
};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        minl = min(minl, l);
        maxr = max(maxr, r);

        int lmid = (r + l) / 2; //取左中点
        int rmid = (r + l + 1) / 2; //取右中点
        if (lmid != rmid) //线段长度为偶数
            rmids[rmid]++; //记录右中点
        else
            lmids[lmid]++;
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        minl = min(minl, l);
        maxr = max(maxr, r);
        v.push_back({ l, r });
    }
    for (int i = minl; i <= maxr; i++)
    {
        f[i] = f[i - 1]; 
        if (rmids.count(i)) //i是某部分偶数长线段的右中点
            f[i] += rmids[i];
        if (lmids.count(i)) //i是某部分奇数长线段的中点
            f[i] += lmids[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l = v[i].first, r = v[i].second;
        if (rmids.count(l)) //区间左端点l刚好位于某线段的右中点，不算框住线段，需要去掉右中点位于l的所有线段
            cout << f[r] - f[l - 1] - rmids[l] << endl;
        else
            cout << f[r] - f[l - 1] << endl;
    }
    return 0;
}