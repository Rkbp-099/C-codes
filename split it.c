#include<stdio.h>
struct node {
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;


void PrintList(Nodeptr head);                  /*Prototype of function PrintList()*/
Nodeptr tailInsert(Nodeptr head, int data);    /*Prototype of function tailInsert()*/

int main()
{
    
    Nodeptr Even = NULL;
    Nodeptr Odd = NULL;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int d;
            scanf("%d",&d);
            if(d%2 == 0)
            {
                Even = tailInsert(Even,d);
            }
            else
            {
                Odd =tailInsert(Odd,d);
            }
        }

        Nodeptr temp3 = Odd;
        while(temp3->next!= NULL)
        {
            temp3 = temp3->next;
        }
        temp3->next = Even;
        

        PrintList(Odd);
        
        Odd  = NULL;
        Even = NULL;
        printf("\n");
    }
    return 0;
} 


/*Definition for function tailInsert() for creating the Linked List by inserting node at tail*/

Nodeptr tailInsert(Nodeptr h, int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    Nodeptr temp1 = h;
    if(h==NULL)
    {
        h = temp;
        temp->next = NULL; 
        
        return h;
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
        
        return h;
    }
}

/*Definition for function PrintList() for printing the Linked List*/

void PrintList(Nodeptr k)
{
    Nodeptr A = k;
    while(A!=NULL)
    {
        int f = A->data;
        printf("%d ",f);
        A = A->next;
        
    }
}