#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* leftC;
    struct node* rightC;
};

typedef struct node* Nodeptr;

Nodeptr insert(int data);
Nodeptr createT(int arr[], int n, int i, Nodeptr root);
void printPost(Nodeptr root);

int main()
{
    int arr[] = {19, 22, 13, 7, 24, 17, 11, 3, 39, 51 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Nodeptr root = NULL;

    root = createT(arr, n, 0, root);

    printPost(root);

    return 0;
}

Nodeptr insert(int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->leftC = NULL;
    temp->rightC = NULL;
    return temp;
}

Nodeptr createT(int arr[], int n, int i, Nodeptr root)
{
    if(i<n)
    {
        Nodeptr temp1 = insert(arr[i]);
        root = temp1;

        root->leftC = createT(arr, n, ((2*i)+1), root->leftC);

        root->rightC = createT(arr, n, ((2*i)+2), root->rightC);
    }
    return root;
}

void printPost(Nodeptr node)
{
    if(node == NULL)
    {
        return;
    }

    printPost(node->leftC);
    
    printPost(node->rightC);

    printf("%d ",node->data);

}
