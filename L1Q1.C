#include <stdio.h>
void maxmin(int arr[],int* n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i+1; j < *n; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
        
    }
        printf("The Largest number is %d \n", arr[*n-1]);
        printf("The Smallest number is %d \n", arr[0]);
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Input the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Input the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    maxmin(arr,&n);


    

    return 0;
}
