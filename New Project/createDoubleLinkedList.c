#include <stdio.h>
#include<malloc.h>

struct block
{
    int data;
    struct block *next;
    struct block *prev; //modified for Double ll
}*curr;
typedef struct block node;
void create(node** start,node** end)
{
    node *temp;
    *start = NULL;
    char ans = 'y';
    while(ans == 'y')
    {
        if(*start == NULL)
        {
             curr = (node*)malloc(sizeof(node));
             *start = curr;
             curr->prev = NULL; //modified for Double ll
             printf("Enter data \n");
             scanf("%d",&curr->data);
        }else
        {
            curr->next = (node*)malloc(sizeof(node));
            temp = curr;        //modified for Double ll
            curr = curr->next;  //modified for Double ll
            curr->prev = temp;
            printf("Enter data \n");
            scanf("%d",&curr->data);
            curr->next = NULL;
        }
        printf("Do yoy want to enter more node ?\n");
        scanf(" %c",&ans);
       
    }
    *end = curr;

}
void rev(node **end)
{
    curr =*end;
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->prev;
    }
}
void show(node **start)
{
    curr =*start;
    while(curr!=NULL)
    {
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}

int main()
{
    node *start,*end,*start1,*end1;
    create(&start,&end);
    create(&start1,&end1);
    printf("Your Linked list \n");
    show(&start);
    printf("Reversed Linked List \n");
    rev(&end);
    printf("Your Linked list \n");
    show(&start1);
    printf("Reversed Linked List \n");
    rev(&end1);
    return 0;
}