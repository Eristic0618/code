//https://www.acwing.com/problem/content/907/
#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define INF 0x3f3f3f3f

int n, cnt;
vector<pair<int, int>> v;
bool check[N];

template <class T>
struct cmp{
    bool operator()(const T& a, const T& b)
    {
        return a.second < b.second;
    }
};

int main()
{
    cin >> n;
    for(int i = 0 ;i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp<pair<int, int>>()); //按区间右端点从小到大排序
    int ed = -INF; //贪心：每次只取区间右端点，能够覆盖到更多的区间
    for(int i = 0;i < n; i++)
    {
        if(v[i].first > ed) //如果某区间左端点大于上一区间的右端点，代表必须要新增一个点
        {
            ed = v[i].second; 
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}