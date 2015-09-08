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

//function to reverse LL
struct node* rev()
{
    struct node *temp = NULL ,*r;
    curr = head;
    while(curr!=NULL)
    {
        r = (struct node*)malloc(sizeof(struct node));
        r->data = curr->data;
        r->next = temp;
        temp = r;
        curr = curr->next;
    }
    return temp;
}
int main()
{
    struct node *r;
	input();
	r = rev();
	printf("\nReversed List : \n");
	show(r);
	printf("\nOriginal list :\n");
	show(head);
	return 0;
}