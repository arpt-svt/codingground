#include <stdio.h>

int main()
{
    int i=0;
    char *name[]={"abc","def","ghi","ijk","lmn","nop","pqr","rst","tuv","vwx","xyz"};
    char** gp1;
    char** gp2;
    char** gp3;
    gp1 = &name[0];
    gp2 = &name[5];
    gp3 = &name[8];
    for(i=0;i<3;i++)
    {
        printf("%s \n",*gp2++);
    }
    
    return 0;
}

