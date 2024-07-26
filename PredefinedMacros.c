#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char const *argv[])
{
    printf("the file name is %s\n",__FILE__);
    printf("todays date is %s\n",__DATE__);
    printf("line no is %d\n",__LINE__);
    printf("ansi : %d\n",__STDC__);
    return 0;
}
