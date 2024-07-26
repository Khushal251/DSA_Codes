#include <stdio.h>
void diff(int arr[],int* n)
{

        printf("The difference between the last and the second last number is %d \n", arr[*n-1]-arr[*n-2]);
   
    
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
    diff(arr,&n);


    

    return 0;
}
