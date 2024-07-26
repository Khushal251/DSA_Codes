#include <stdio.h>

union student
{
    int id;
    int marks;
    char fav_char;
    char name[100];
};

int main(int argc, char const *argv[])
{

    union student s1;
    s1.id=6;
    s1.marks=45;          
    s1.fav_char='u';
    strcpy(s1.name,"harry");     //last one got printed and others got garbege value


    printf("the id is %d\n", s1.id);
    printf("the marks is %d\n", s1.marks);
    printf("the name is %s\n", s1.name);

    return 0;
}