#include <stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
}*head,*current;
int main()
{
    int i;
    current = (struct node*)malloc(sizeof(struct node));
    head = current;
    current->data = 120;
    for(i=1;i<5;i++)
    {
        current->next = (struct node*)malloc(sizeof(struct node));
        current = current->next;
        current->data = i;
        current->next=NULL;
    }
    current = head;
    for(i=0;i<5;i++)
    {
        printf("%d\n",*current);
        current = current->next;
    }
    return 0;
}