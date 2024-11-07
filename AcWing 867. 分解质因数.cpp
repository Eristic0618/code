// https://www.acwing.com/problem/content/869/
#include <iostream>
using namespace std;

void devide(int n)
{
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
        {
            int s = 0;
            while (n % i == 0)
            {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    if (n > 1)
        printf("%d %d\n", n, 1);
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        devide(a);
    }
    return 0;
}