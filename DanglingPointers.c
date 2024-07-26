// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char const *argv[])
// {
//     // case 1 : De allocation of the memory block
//     int *ptr=(int*)malloc(7*sizeof(int));
//     ptr[0]=23;
//     ptr[1]=31;
//     ptr[2]=67;
//     ptr[3]=94;
//     free(ptr); //ptr is now a dangling pointer
    
//     return 0;
// }




// // case 2 : function returning local variable address
// #include <stdio.h>
// #include <stdlib.h>

// int* func()
// {
//     int a,b,sum;
//     a=45;
//     b=23;
//     sum=a+b;
//     return &sum;
// }

// int main(int argc, char const *argv[])
// {
//     int* ptr= func();   //ptr is now a dangling pointer

//     return 0;
// }




// case 3 : when variable goes out of scope
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int* ptr;
    {
        int a=4;
        ptr=&a;
    }
    //here variable a goes out of scope which means ptr is pointing to a location which is freed and hance ptr is now a dangling pointer

    
    return 0;
}
