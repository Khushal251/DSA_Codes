#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
void printgm(int (*abc)(int, int))
{
    printf("Hello World good morning\n");
    printf("the sum of 5 & 7 is %d\n", abc(5,7));     //why didnt we derefrence it here
}

int main(int argc, char const *argv[])
{
    int c;
    int (*fptr)(int, int);
    fptr = &sum;
    c = (*fptr)(3, 4);
    printf("the sum of 3 and 4 is %d\n", c);
    printgm(fptr);


    return 0;
}
