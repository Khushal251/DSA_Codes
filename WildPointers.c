#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a=345;
    int *ptr;   //this is a wild pointer

    ptr=&a;   //the pointer is no longer a wild pointer
    printf("the value of a is %d\n", *ptr);
    return 0;
}
