//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
#include <stdio.h>

int main()
{
    int soda = 20;
    int empt = soda;
    int drink = 0;
    do
    {
        drink = drink + soda;
        empt = soda;
        soda = 0;
        while (empt > 1)
        {
            soda++;
            empt = empt - 2;
        }
    } while (soda != 0);
    printf("%d", drink);
    return 0;
}