#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10],arr2[10],sum=0;
    printf("enter the numbers\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
        for (int i = 0; i < 10; i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if (arr[i] == arr2[j])
            {
                sum=sum+1;
                break;
            }
        }
    }
    printf("the total number of dublicate numbers is %d\n", sum);
    printf("the total number of unique numbers is %d\n", 10-sum);


    return 0;
}