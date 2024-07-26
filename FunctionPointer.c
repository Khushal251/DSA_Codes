#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
int main(int argc, char const *argv[])
{
    int c;
    printf("the sum of the two numbers is %d\n", sum(2, 3));              //int a=2;
    int (*fptr)(int, int);            //declaring a pointer same as int *ptr;
    fptr = &sum;                      //giving the address of a function to the pointer same as ptr=&a;
    c = (*fptr)(4, 5);                //derefrencing the pointer to get the value inside it same as c=*(ptr); 
    printf("the value of c is %d\n", c);

    return 0;
}