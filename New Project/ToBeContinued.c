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
    struct node *temp;
    int item;
    curr=head;
    printf("Enter item to delete :\n");
    scanf("%d",&item);
    newNode->next=NULL;


    if(curr->data == item)
    {
       // temp = head;        //for 1st pos
        head = head->next;
       // free(temp);
        printf("ok");
    }
    else 
    {
    while(curr->next != NULL )
    {
        if(curr->next->data == item)
        {
           break;
        }
        curr = curr->next;
    }
    
    if(curr->next == NULL)
    {
        printf("Element not found \n");
    }
    else
    {
        temp = curr->next;
        curr->next = curr->next->next;  //for the rest pos
        free(temp);
    }
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