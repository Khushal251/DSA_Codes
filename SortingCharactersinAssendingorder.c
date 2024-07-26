#include <stdio.h>

int main(int argc, char const *argv[])
{
  char str[40], c;
  int n = 0;
  printf("enter the string\n");
  gets(str);
  puts(str);

  for (int i = 0; str[i] != '\0'; i++)
  {
    for (int j = i + 1; str[j] != '\0'; j++)
    {
      if (str[i] > str[j])    //here we can compare the characters as numbers as we do in simple sorting where we compare numbers
      {                       //because each character are assinged by a number eg. c=104,d=106,e=108....increasing order
        c = str[i];
        str[i] = str[j];  
        str[j] = c;
      }
    }
  }
  printf("%s", str);

  return 0;
}
