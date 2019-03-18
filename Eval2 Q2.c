#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    char name[50];
    char gen[50];
    char city[50];
    char ph[50];
    int id;
    struct node* next;
};

typedef struct node* Nodeptr;


Nodeptr tailInsert(Nodeptr head, char name[], char gen[], char city[], char ph[], int id);
Nodeptr search(Nodeptr head, int id);
void PrintList(Nodeptr head);
Nodeptr DelElem(Nodeptr h, int id);



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        Nodeptr head = NULL;
        for(int i=0;i<n;i++)
        {
            char name[50];
            char gen[50];
            char city[50];
            char ph[50];
            scanf("%s",name);
            scanf("%s",gen);
            scanf("%s",city);
            scanf("%s",ph);
            
            head = tailInsert(head, name, gen, city, ph, i);
        }
        
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            Nodeptr g = search(head,k);
            PrintList(g);
            if(k != 0){
                Nodeptr temp = head;
                for(int i=0;i<(k-1);i++)
                {
                    temp = temp->next;
                }
                temp->next = g->next;
            }
            else if(k == 0){
                head = g->next;
            }
            
           
        }
        
        
    } 
    return 0;
}

/*Definition for function tailInsert() for creating the Linked List by inserting node at tail*/

Nodeptr tailInsert(Nodeptr head, char name[], char gen[], char city[], char ph[], int id)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    strcpy(temp->name ,name);
    strcpy(temp->gen ,gen);
    strcpy(temp->city ,city);
    strcpy(temp->ph ,ph);
    temp->id = id;
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

/*s2 Definiton*/

Nodeptr search(Nodeptr head, int id)
{
    Nodeptr H = head;
    if(H != NULL)
    {
        for(int i=0;i<id;i++)
        {
            H = H->next;
        }
        return H;
    }
}



/*Definition for function PrintList() for printing the Linked List*/

void PrintList(Nodeptr h)
{
    Nodeptr A = h;
    if(A!=NULL)
    {
        printf("%s ",A->name);
        printf("%s ",A->gen);
        printf("%s ",A->city);
        printf("%s\n",A->ph);
    }
}
        
        
        
        
        
        
        
        
        
        
        
        