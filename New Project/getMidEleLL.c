#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*curr;

void input()
{
	char ans ='y';
	head = NULL;
	while(ans=='y')
	{
		if(head == NULL)
		{
			 head = (struct node *)malloc(sizeof(struct node));
			 curr=head;
		}else
		{
			curr->next = (struct node *)malloc(sizeof(struct node));
			curr = curr->next;
		}
		printf("\nEnter Data :");
		scanf("%d",&curr->data);
		curr->next = NULL;
		printf("\ndo you want to enter more (y/n):");
		scanf(" %c",&ans); //white space is used before %c to remove mess with upper printf statement
	} 
}

void show(struct node *head)
{
	curr=head;
	while(curr != NULL)
	{
		printf("\n%d\t\n",curr->data);
		curr = curr->next;
	}
}
// to get middle element of LL
void getMid(struct node *start)
{
    struct node *step1 = start,*step2 = start;
    while(step2!=NULL && step2->next != NULL)
    {
        step1 = step1->next;
        step2 = step2->next->next;
    }
    printf("\nMidd ele : %d \n",step1->data);
}
int main()
{
	input();
	printf("\nYour list :\n");
	show(head);
    getMid(head);
	return 0;
}