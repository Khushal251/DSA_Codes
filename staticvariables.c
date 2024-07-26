#include <stdio.h>
int func1(int b1)
{
    static int myvar=0;
    printf("the value of myvar is %d\n",myvar);
    myvar++;
}

int main(int argc, char const *argv[])
{
    int b=3;
    func1(b);
    func1(b);
    func1(b);
    func1(b);
    
    return 0;
}
