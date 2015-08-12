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
	printf("\nYour List\n")
	while(curr != NULL)
	{
		printf("\n%d\t\n",curr->data);
		curr = curr->next;
	}
}

void insertBeg()
{
	curr=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d",&newNode->data);
    //logic for insertion at begining
    newNode->next = head;
    head = newNode;
}
void insertLast()
{
    curr=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d",&newNode->data);
    //logic to reach the last node
    while(curr->next!=NULL)
    {
        curr = curr->next;
    }
    //logic to insert
    curr->next = newNode;
    newNode->next = NULL;
}
void insertMid(int pos)
{
    int i=1;
    curr=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :\n");
    scanf("%d",&newNode->data);
    //logic to reach the req node
    while(i<pos-1)
    {
        curr = curr->next;
        i++;
    }
    //logic to insert 
    newNode->next = curr->next;
    curr->next = newNode;
}
int main()
{
	input();
	show();
	//insertbeg();
	insertMid(2);
	show();
	return 0;
}