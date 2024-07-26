#include <stdio.h>
int sum(char str[])
{
    int a = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        a += (str[i] - '0');
    }
    printf("%d\n", a);
}

int main(int argc, char const *argv[])
{
    char str[] = "125";
    sum(str);
    return 0;
}
