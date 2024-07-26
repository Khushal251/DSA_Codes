#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char str[n];
        scanf("%s",&str);
        char temp, k[n];
        int i = 0;
        if (n % 2 == 0)
        {
            while (i < n)
            {
                temp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = temp;
                i = i + 2;
            }
        }
        else if (n % 2 != 0)
        {
            while (i < n - 1)
            {
                temp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = temp;
                i = i + 2;
            }
            
        }
        char j, a[n];
        for(int i=0;i<n;i++)
        {
            for (j = 'a'; j <= 'z'; j = j + 1)
            {
                if (k[i] == j)
                {
                    a[i] = 'z' + 'a' - j;
                }
            }
        }
        printf("%s\n",a);
    }
    return 0;
}