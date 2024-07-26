
#include <stdio.h>
#include <stdlib.h>

int digit(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    for (int i = 10; i <= 99; i++)
    {
        if (digit(i) % 7 == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}