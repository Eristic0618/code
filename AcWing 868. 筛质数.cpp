// https://www.acwing.com/problem/content/870/
#include <iostream>
#include <vector>
using namespace std;

const int N = 1000010;

vector<int> prime;
bool is_prime[N];

// void Eratosthenes(int n) //埃式筛
// {
//     for(int i = 2;i <= n;i++) is_prime[i] = true;//除0和1外都默认为素数
//     for(int i = 2;i <= n;i++)
//     {
//         if(is_prime[i]) prime.push_back(i);
//         for(int j = i + i;j <= n;j += i)
//         {
//             is_prime[j] = false;
//         }
//     }
// }

void pre(int n) // 欧拉筛
{
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);
        for (int j = 0; prime[j] <= n / i; j++)
        {
            is_prime[prime[j] * i] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    pre(n);
    cout << prime.size() << endl;
    return 0;
}