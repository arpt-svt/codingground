#include <stdio.h>
#include<malloc.h>
#define max(a,b) (((a)>(b))?(a):(b))
struct node
{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL,*temp;

struct node* getNode(int data)
{
    temp = (struct node *)malloc(sizeof(struct node) ); 
    temp->data = data;
    temp->left =NULL;
    temp->right=NULL;
    return temp;
}


struct node* insertNode(struct node* root,int data)
{
    if(root == NULL)
    {
        root = getNode(data);
        return root;
    }
    else if(data<=root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else{
        root->right = insertNode(root->right,data);
    }
    return root;
}

int HOT(struct node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        return (max(HOT(root->left),HOT(root->right))+1);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d   ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        preorder(root->left);
        printf("%d   ",root->data);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        preorder(root->left);
        preorder(root->right);
        printf("%d   ",root->data);
    }
}
int main()
{
    root = insertNode(root,15);
    root = insertNode(root,10);
    root = insertNode(root,16);
    root = insertNode(root,8);
    root = insertNode(root,11);
    root = insertNode(root,6);
    printf("%d\n",HOT(root));
    printf("\nPreorder :- ");
    preorder(root);
    printf("\nPostoreder :- ");
    postorder(root);
    printf("\nInorder :- ");
    inorder(root);
    return 0;
}

