#include <stdio.h>

int main()
{
    char str[50] = "Arpit Srivastava  ";
    char *str1[] = {"Arpit Srivastava ","Heyy there"};
    char** ptr = &str1[1];
    printf("%s\n%s\n%s\n",str,str1[0],*ptr);
    return 0;
}

