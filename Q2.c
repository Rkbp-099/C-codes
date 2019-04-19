#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* leftC;
    struct node* rightC;
};

typedef struct node* Nodeptr;

void printInorder(Nodeptr root);
Nodeptr createNode(int data);
void insert(Nodeptr* root, int val);
Nodeptr BST(int arr[], int n);
void printInorder(Nodeptr root);
int main()
{
    int arr[] = {19, 22, 13, 7, 24, 17, 11, 3, 39, 51 };
    int n = sizeof(arr)/sizeof(0);

    Nodeptr root = BST(arr, n);

    printInorder(root);
    return 0;
}

Nodeptr createNode(int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->leftC = NULL;
    temp->rightC = NULL;
    return temp;
}

void insert(Nodeptr* root, int val)
{
    if(*root == NULL)
    {
        *root = createNode(val);
    }
    else if(val > (*root)->data)
    {
        insert(&((*root)->rightC), val);
    }
    else if(val < (*root)->data)
    {
        insert(&((*root)->leftC), val);
    }
}

Nodeptr BST(int arr[], int n)
{
    Nodeptr root = NULL;
    for(int i=0;i<n;i++)
    {
        insert(&root, arr[i]);
    }
    return root;
}

void printInorder(Nodeptr root)
{
    if(root && root->leftC)
        printInorder(root->leftC);
    if(root)
        printf("%d ",root->data);
    if(root && root->rightC)
        printInorder(root->rightC);
}
