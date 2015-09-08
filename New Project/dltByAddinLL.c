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

//to delete an element by address

void dltByAdd(struct node **add)
{
    struct node *temp;
    if(*add->next == NULL)
    {
        *add=NULL;
        
    }else
    {
        temp =*add->next;
        *add->data = temp->data;
        *add->next = temp->next;
        free(temp);
    }
}
int main()
{
	input();
	printf("\nYour list :\n");
	show(head);
	dltByAdd(&head->next->next); //head->next->next is address of 3rd element
	
	printf("\nYour list after deletion :\n");
	show(head);
	return 0;
}