#include<stdio.h>
struct node {
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;

Nodeptr tailInsert(Nodeptr head, int data);    /*Prototype of function tailInsert()*/
void PrintList(Nodeptr head);                  /*Prototype of function PrintList()*/
Nodeptr DelElem(Nodeptr h, int data);          /*Prototype of function DelElem()*/
int max(Nodeptr head);                         /*Prototype of function max()*/


int main()
{
    Nodeptr head = NULL;
    Nodeptr newHead = NULL;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int g;
            scanf("%d",&g);
            head = tailInsert(head, g);
        }
        
        for(i=0;i<n;i++)
        {
            int m = max(head);
            head = DelElem(head,m);
            newHead = tailInsert(newHead,m);
        }

        PrintList(newHead);
        printf("\n");
        newHead = NULL;
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

/* Definition for finding MAX element*/

int max(Nodeptr head)
{
    Nodeptr ptr = head;
    int k = ptr->data;
    Nodeptr ptrn = ptr->next;
    while(ptrn!=NULL)
    {
        int b = ptrn->data;
        if(k<b)
        {
            k = b;
        }
        ptrn = ptrn->next;
    }
    return k;
}



/*Delete element Definiton*/

Nodeptr DelElem(Nodeptr h, int data)
{
    Nodeptr temp = h;
    if(temp->data == data)
    {
        h = temp->next;
    }
    else
    {
        
        while(temp->next!=NULL)
        {
            Nodeptr temp1 = temp->next;
            if(temp1->data == data)
            {
                temp->next = temp1->next;
                break;
            }
            
            temp = temp->next;
        }
    }
        return h;
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