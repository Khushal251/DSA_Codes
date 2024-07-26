#include <stdio.h>
// defining a new data type just like int
struct student
{
    int id;
    int marks;
    char fav_char;
    char name[100];
};

int main(int argc, char const *argv[])
{

    struct student harry, ravi, shubham; // int a,b,c;   or we can do      struct student harry={4,800,'p',"harry chaudhary"}
    harry.id = 4;                        // a=4;                           it is just like     int a=4; 
    ravi.id = 6;                         // b=6;
    shubham.id = 2;                      // c=2;
    harry.marks = 800;
    ravi.marks = 700;
    shubham.marks = 900;
    harry.fav_char = 'p';
    ravi.fav_char = 'u';
    shubham.fav_char = 'l';
    strcpy(harry.name, "harry chaudhary"); // here harry.name[100]=" harry chaudhary " is not allowed
    strcpy(ravi.name, "rav kishan");
    strcpy(shubham.name, "shubham mishra");

    printf("the id of the student named harry is %d\n", harry.id);
    printf("the favourate character of the student named ravi is %c\n", shubham.fav_char);
    printf("the full name of the student named harry is %s\n", harry.name);

    return 0;
}