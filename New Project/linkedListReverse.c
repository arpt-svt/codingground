#include <stdio.h>
#include<malloc.h>

struct block
{
    int data;
    struct block *next;
}*curr;
typedef struct block node;
node* create()
{
    node *start = NULL; 
    char ans = 'y';
    while(ans == 'y')
    {
        if(start == NULL)
        {
             curr = (node*)malloc(sizeof(node));
             start = curr;
             printf("Enter data \n");
             scanf("%d",&curr->data);
        }else
        {
            curr->next = (node*)malloc(sizeof(node));
            curr = curr->next;
            printf("Enter data \n");
            scanf("%d",&curr->data);
            curr->next = NULL;
        }
        printf("Do yoy want to enter more node ?\n");
        scanf(" %c",&ans);
       
    }
    return start;
}

void show(node *start)
{
    curr =start;
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}
node* rev(node *start)
{
    node *nextA,*prevA=NULL;
    curr= start;
    while(curr!=NULL)
    {
        
        nextA=curr->next;
        curr->next =prevA;
        prevA = curr;
        curr = nextA;
    }
    start = prevA;
    return start;
}
int main()
{
    node *start,*r;
    start = create();
    show(start);
    printf("-----------------------------\n");
    r = rev(start);
    show(start);
    printf("After Reversing \n");
    show(r);
    return 0;
}
