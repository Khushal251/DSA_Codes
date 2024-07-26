// The wrost case occurs when leftmost (or rightmost) element is chosen as a pivot, the worst occurs in the following cases. 

// 1) Array is already sorted in the same order. 
// 2) Array is already sorted in reverse order. 
// 3) All elements are the same.


#include <stdio.h>
void swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
 
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
 
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(int);
      printf("Before sorting\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
      printf("After sorting\n");
      
    printArray(arr, size);
    return 0;
}