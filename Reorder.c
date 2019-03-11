#include<stdio.h>
struct node{
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;

Nodeptr tailInsert(Nodeptr head, int data);
void PrintList(Nodeptr head);
int search(Nodeptr head, int data);


int main()
{
    Nodeptr head = NULL;
    Nodeptr rehead = NULL;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int g;
            scanf("%d",&g);
            head = tailInsert(head, g);
        }
        
        for(j=0;j<n;j++)
        {
            int idx;
            scanf("%d",&idx);
            int m = search(head, idx);
            rehead = tailInsert(rehead, m);
        }
        
        PrintList(rehead);
        printf("\n");
        rehead = NULL;
        head   = NULL;
    }
    return 0;
}

/*Definition for function tailInsert() for creating the Linked List by inserting node at tail*/

Nodeptr tailInsert(Nodeptr head, int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    Nodeptr temp1 = head;
    if(head==NULL)
    {
        head = temp;
        temp->next = NULL; 
        
        return head;
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
        
        return head;
    }
}

/*Definition for function search() for searching the Linked List*/

int search(Nodeptr head, int data)
{
    Nodeptr temp = head;
    for(int i=0;i<(data);i++)
    {
        temp = temp->next;
    }
    int d = temp->data;
    return d;
}


/*Definition for function PrintList() for printing the Linked List*/

void PrintList(Nodeptr head)
{
    Nodeptr A = head;
    while(A!=NULL)
    {
        int f = A->data;
        printf("%d ",f);
        A = A->next;
        
    }
}



























        
        