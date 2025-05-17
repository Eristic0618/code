//https://www.acwing.com/problem/content/127/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 50050;

int n, ans = -1e11, sum;
vector<pair<int, int>> v;

template<class T>
struct cmp{
    bool operator()(const T& a, const T& b)
    {
        return a.first+a.second < b.first+b.second;
    }
};

signed main()
{
    //在交换前，第i头牛的危险系数=（w_1+...+w_i-1）-s_i，第i+1头牛的危险系数=（w_1+...+w_i-1）+w_i-s_i+1
    //将两只牛交换后，第i头牛的危险系数=（w_1+...+w_i-1）+w_i+1-s_i，第i+1头牛的危险系数=（w_1+...+w_i-1）-s_i+1
    //括号内的内容可以省略，易证w_i+1-s_i > -s_i, w_i-s_i+1 > -s_i+1，所以只需要比较w_i+1-s_i和w_i-s_i+1哪个更大
    //如果w_i-s_i+1大于w_i+1-s_i，即w_i+s_i大于w_i+1 + s_i+1，则交换后危险系数的最大值会降低
    //因此我们只需要将每只牛的重量和能力值相加，然后将从上到下升序排序即可
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp<pair<int,int>>());
    for(int i = 0;i < n; i++)
    {
        ans = max(ans, sum - v[i].second);
        sum += v[i].first;
    }
    cout << ans << endl;
    return 0;
}