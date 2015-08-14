#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head,*curr,*newNode;

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
		scanf(" %c",&ans);
	}
}

void show()
{
	curr=head;
	printf("\nYour List\n");
	while(curr != NULL)
	{
		printf("\n%d\t\n",curr->data);
		curr = curr->next;
	}
}


void insert()
{
    
    curr=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    //logic to reach the req node
    while(curr->next != NULL && curr->next->data <= newNode->data )
    {
        curr = curr->next;
    }
    
    //logic to insert 
    if(curr->data >= newNode->data)
    {
        newNode->next = curr;       //for 1st pos
        head = newNode;
    }else if(curr->next == NULL)
    {
        printf("ok");
        curr->next = newNode;    // for last pos
        newNode->next = NULL;
    }
    else
    {
    newNode->next = curr->next;
    curr->next = newNode;
    }
}
int main()
{
	input();
	show();
	insert();
	show();
	return 0;
}