#include <stdio.h>

int main()
{
    int i=0;
    char *name[]={"abcarpitaabilllij","def","ghi","ijk","lmn","nop","pqr","rst","tuv","vwx","xyz"};
    char** gp1;
    char** gp2;
    char** gp3;
    char *ptr;
    gp1 = &name[0];
    gp2 = &name[5];
    gp3 = &name[8];
    printf("Address of the elements in pointer array :\n");
    for(i=0;i<11;i++)
    {
        printf("%u --> %s\n",&name[i],name[i]);
        ptr = name[i];
        printf("\t add of 1st charcter %c --> %u \n",*ptr,ptr);
    }
    return 0;
}