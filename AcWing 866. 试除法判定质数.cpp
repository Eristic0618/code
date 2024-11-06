// https://www.acwing.com/problem/content/868/
#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (is_prime(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}