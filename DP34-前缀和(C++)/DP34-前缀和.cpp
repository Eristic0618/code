//����һ������Ϊn������
//��������q�β�ѯ, ÿ�β�ѯ����������l, r.
//����ÿ��ѯ��, �����ǰ׺Ϊl��r֮�������֮��
//��һ�а�����������n��q.
//�ڶ��а���n������
//������q��,ÿ�а�����������l��r.
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