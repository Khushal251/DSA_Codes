#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int a=34;
    // int *ptr=&a;
    // printf("the address of a is %lf\n", ptr);
    // printf("the value of a is %d\n", *ptr);

    // int a=34;
    // int *ptr=NULL;
    // printf("the address of a is %lf\n", ptr);
    // printf("the value of a is %d\n", *ptr);     //it is wrong, you cannot derefrence a null pointer, program will be stopped
    // //so the new program will be

    int a=34;
    int *ptr=NULL;
    if (ptr!=NULL)
    {
        printf("the value of a is %d\n", *ptr);
    }
    else
    {
        printf("the pointer is a null pointer and cannot be derefrenced\n");
    }
    



    return 0;
}
