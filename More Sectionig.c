#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;

struct Mnode{
    int data;
    int id;
    struct Mnode* link;
};

typedef struct Mnode* Mnodeptr;

Nodeptr tailInsert(Nodeptr head, int data);    /*Prototype of function tailInsert()*/ 
Mnodeptr jackInsert(Mnodeptr head, int data, int id);
void PrintList(Nodeptr head);                  /*Prototype of function PrintList()*/
int min(Mnodeptr head);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,k,j;
        scanf("%d%d",&n,&k);
        
        if(k>n){
            for(int i=0;i<n;i++)
            {
                int j;
                scanf("%d",&j);
                printf("%d\n",j);
            }
        }
        else{
            Nodeptr heads[k];
            Mnodeptr sums =NULL;
    
            for(int i=0;i<k;i++)
            {
                heads[i] = NULL;
            }
        
            for(i=0;i<k;i++)
            {
                int g;
                scanf("%d",&g);
                heads[i] = tailInsert(heads[i], g);
                int r = sum(heads[i]);
                sums = jackInsert(sums, r, i);
            }                           
        
            for(int i=0;i<n-k;i++)
            {
                int m;
                scanf("%d",&m);
                int idx = min(sums);
                heads[idx] = tailInsert(heads[idx], m);
                Mnodeptr temp = sums;
                for(int i=0;i<(idx);i++)
                {
                    temp = temp->link;
                }
                temp->data = (temp->data + m) ;
            }
        
            for(int i=0;i<k;i++)
            {
                PrintList(heads[i]);
                printf("\n");
            }
        
        }
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
/*Definition for function jackInsert() */

Mnodeptr jackInsert(Mnodeptr head, int data, int id)
{
    Mnodeptr temp = (Mnodeptr)malloc(sizeof(struct Mnode));
    temp->data = data;
    temp->id = id;
    temp->link = NULL;
    Mnodeptr temp1 = head;
    if(head==NULL)
    {
        head = temp;
        temp->link = NULL; 
        
        return head;
    }
    else
    {
        while(temp1->link!=NULL)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
        temp->link = NULL;
        
        return head;
    }
}

/*Definition for function sum() for calculating the sum of Linked List*/

int sum(Nodeptr h)
{
    Nodeptr temp = h;
    int s = 0;
    while(temp!= NULL)
    {
        int d = temp->data;
        s = s + d;
        temp = temp->next;
    }
    return s;
}

/* min() for calculating the minimum*/

int min(Mnodeptr head)
{
    Mnodeptr ptr = head;
    int k = ptr->data;
    int idx = ptr->id;
    Mnodeptr ptrn = ptr->link;
    while(ptrn!=NULL)
    {
        int b = ptrn->data;
        int nidx = ptrn->id;
        if(k>b)
        {
            k = b;
            idx = nidx;
        }
        ptrn = ptrn->link;
    }
    return idx;
}

/*Definition for function PrintList() for printing the Linked List*/

void PrintList(Nodeptr h)
{
    Nodeptr K = h;
    while(K!=NULL)
    {
        int f = K->data;
        printf("%d ",f);
        K = K->next;
        
    }
}
