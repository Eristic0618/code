#include <stdio.h>

int main(void)
{
    int arr[10] = {0};
    int sum = 0;
    double avg = 0;
    int i = 0;
    while(i<10)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
        i++;
    }    
    avg = sum / 10.0;
    printf("%lf\n", avg);
}