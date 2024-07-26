// 3.	With the help of quick sort, find the kth smallest element in an array of n integers. 
#include <stdio.h>


void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }


    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
     printf("\n");

     int k;
    printf("Enter the value of k(the kth smallest element)\n");
     scanf("%d",&k);
     if(k>n)
     {
        printf("Invalid input\n");
     }
     else
     {
    printf("the kth smallest element is %d\n",arr[k-1]);


     }


    return 0;
}
