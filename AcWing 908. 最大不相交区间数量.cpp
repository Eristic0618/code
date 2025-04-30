//https://www.acwing.com/problem/content/910/
#include <bits/stdc++.h>
using namespace std;

#define N 1000010

template<class T>
class cmp {
public:
    bool operator()(const T& a, const T& b)
    {
        return a.second < b.second;
    }
};

int n;
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end(), cmp<pair<int, int>>()); //按区间右端点排序
    
    int ed = v[0].second, cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[i].first > ed)
        {
            ed = v[i].second;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}