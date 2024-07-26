// // use of auto storage class

// #include <stdio.h>
// int func(int a, int b)
// {
//     auto int sum;     // or we can simply writr int sum here i.e. int sum = auto int sum by default.
//     sum=a+b;
//     return sum;                                
// }
// int main(int argc, char const *argv[])
// {
//     int ace;
//     ace = func(2, 3);
//     printf("the sum is %d\n", ace);
//     return 0;
// }





// // use of extern keyword

// #include <stdio.h>

// int sum = 333;
// int func(int a, int b)
// {
//     extern int sum;      // if we didnt write extern it will gives garbage value because no value of sum is present in local function, 
//     return sum;          //  extern says that take the value from the global variable.                      
// }
// int main(int argc, char const *argv[])
// {
//     int ace;
//     ace = func(2, 3);
//     printf("the sum is %d\n", ace);
//     return 0;
// }

// // use of extern keyword

// // in the file named StorageClassC
// #include <stdio.h>
// #include "temp.c"

// extern int ace;
// int main(int argc, char const *argv[])
// {
//     printf("the sum is %d\n", ace);
//     return 0;
// }




// // // using ststic storage

// #include <stdio.h>
// int myfunc(int a, int b)
// {
//     static int myvar;
//     myvar++;
//     printf("the myvar is %d\n", myvar);

//     return myvar;                                
// }
// int main(int argc, char const *argv[])
// {
//     int a;
//     a=myfunc(3,2);
//     a=myfunc(3,2);
//     a=myfunc(3,2);
//     a=myfunc(3,2);
    
//     return 0;
// }




// // using regester storage class

// #include <stdio.h>
// int func(int a, int b)
// {
//     register int sum;       // just by showing output we cannt says that it is register storage class.
//     sum=a+b;
//     return sum;                                
// }
// int main(int argc, char const *argv[])
// {
//     int ace;
//     ace = func(2, 3);
//     printf("the sum is %d\n", ace);
//     return 0;
// }

