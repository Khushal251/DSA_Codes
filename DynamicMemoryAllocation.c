#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // int *ptr;
    // int n;
    // printf("enter the size of the array\n");
    // scanf("%d", &n);
    // ptr = (int *)malloc(n * sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %d element of the array\n", i);
    //     scanf("%d", &ptr[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("the value of %d element of the array is %d\n", i, ptr[i]);
    // }




    // // use of calloc
    // int *ptr;
    // int n;
    // printf("enter the size of the array\n");
    // scanf("%d", &n);
    // ptr = (int *)calloc(n , sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %d element of the array\n", i);
    //     scanf("%d", &ptr[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("the value of %d element of the array is %d\n", i, ptr[i]);
    // }
    // // if we didnt assign any values for arr[i] the in calloc the output gives 0 as the return value instead of any garbage value
    // // i.e.    the value of 0 element of the array is 0
    // //         the value of 1 element of the array is 0
    // //         the value of 2 element of the array is 0




    // use of realloc
    int *ptr;
    int n;
    printf("enter the size of the array\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element of the array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("the value of %d element of the array is %d\n", i, ptr[i]);
    }

    printf("enter the new size of the array\n");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));
     for (int i = 0; i < n; i++)
    {
        printf("enter the %d element of the new array\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("the value of %d element of the new array is %d\n", i, ptr[i]);
    }




    // free(ptr);


    return 0;
}
