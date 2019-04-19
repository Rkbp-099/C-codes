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
void printPre(Nodeptr node);
void InsertSort(int arr[], int n);
void reverse(int arr[], int n);

int main()
{
    int arr[] = { 19, 22, 13, 7, 24, 17, 11, 3, 39, 51 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Nodeptr root = NULL;

    InsertSort(arr, n);
    reverse(arr, n);

    root = createT(arr, n, 0, root);

    printPre(root);

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

void InsertSort(int arr[], int n)
{
    int i, sp, j; 
    for (i = 1; i < n; i++)
    { 
        sp = arr[i]; 
        j = i - 1; 
        
        while (j >= 0 && arr[j] > sp) 
        { 
           arr[j + 1] = arr[j]; 
           j = j - 1; 
        } 
           arr[j + 1] = sp; 
    }
}

void reverse(int arr[], int n)
{
    int newArr[n];
    for(int i=0,j=n-1;i<n,j>=0;i++,j--)
    {
        newArr[j] = arr[i] ;
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = newArr[i];
    }
}

void printPre(Nodeptr node)
{
    if(node == NULL)
    {
        return;
    }

    printf("%d ",node->data);

    printPre(node->leftC);
    
    printPre(node->rightC);

}
