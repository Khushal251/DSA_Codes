// //reading a file
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     FILE *ptr=NULL;
//     char string[64];

//     ptr=fopen("myfile.txt","r");
//     fscanf(ptr,"%s", string);
//     printf("the content of this file has %s\n", string);
    
//     return 0;
// }



// //writing a file with write mode
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
//     FILE *ptr=NULL;
//     char string[64]="this content was produced by fileiofunctioninclange.c";

//     ptr=fopen("myfile.txt","w");   //with this w(write) mode, the previous content in the myfile.txt got deleted and the lines which we 
//     fprintf(ptr,"%s", string);     //gives, got printed
    
//     return 0;
// }


//writing a file with append mode
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *ptr=NULL;
    char string[64]="this content was produced by fileiofunctioninclange.c";

    ptr=fopen("myfile.txt","a");   //with this a(append) mode, the previous content in the myfile.txt remains there and the lines which we 
    fprintf(ptr,"%s", string);     //gives, got printed with it, without deleting the previous lines
    
    return 0;
}

