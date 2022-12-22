#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};
//Creation of Tree
struct node*insert(struct node*root,int x)
{
    if(root==NULL)
    {
        struct node*temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return root;
    }
    if(x<root->data)
    {
        root->left=insert(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    return root;
}
//Search in BST
struct node*search(struct node*root,int key)
{
    struct node*t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if(key<t->data)
        t=t->left;
        else
        t=t->right;
    }
    return NULL;
}
//Inorder Traversal
void inorder(struct node*ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}
//Main Function
int main()
{
    struct node*root=NULL;
    struct node*temp;
    int data,key;
    int t;
    int i=1;
    printf("How many elements you want to insert = ");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter the elements %d = ",i++);
        scanf("%d",&data);
        root=insert(root,data);
    }
    inorder(root);
    
    printf("\nEnter the key to search\n");
    scanf("%d",&key);
    temp=search(root,key);
    if(temp!=NULL)
    {
        printf("Element %d is found\n",temp->data);
    }
    else
    {
        printf("Elemnt is not found\n");
    }
    return 0;
}
