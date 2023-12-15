//给定一个长度为n的数组
//接下来有q次查询, 每次查询有两个参数l, r.
//对于每个询问, 请输出前缀为l到r之间的数据之和
//第一行包含两个整数n和q.
//第二行包含n个整数
//接下来q行,每行包含两个整数l和r.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int>arr(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> arr[i];
    vector<long long>dp(n + 1);
    for (int i = 1; i < n + 1; i++) dp[i] = dp[i - 1] + arr[i];
    int l, r ;
    while (q--) {
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}