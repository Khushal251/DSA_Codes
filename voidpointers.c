#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a=23;
    float b=67.4;
    void *ptr;
    ptr=&a;
    printf("the value of a is %d\n", *( (int*)ptr));
    ptr=&b;
    printf("the value of b is %0.1f\n", *( (float*)ptr));

    return 0;
}
