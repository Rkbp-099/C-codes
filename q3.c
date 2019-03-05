#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;

// struct stk {
//     Nodeptr head;
//     Nodeptr TOP;
// }stack;

Nodeptr headInsert(Nodeptr head, Nodeptr TOP, int data);
Nodeptr Delhead(Nodeptr head, Nodeptr TOP);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Nodeptr head = NULL;
        Nodeptr TOP = head;
        int l;
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            char ins[10];
            scanf("%s",ins);
            if(ins[1] == 'u'){
                int ele;
                scanf("%d",&ele);
                head = headInsert(head,TOP, ele); 
                TOP = head;
            }
            else if(ins[0] == 'p' && ins[1] == 'o'){
                head = Delhead(head,TOP);
                TOP = head;
                // int c ;
                // c++;
            }
            else if(ins[0] == 't'){
                if(TOP != NULL){
                    printf("%d\n",TOP->data);
                }
                else{
                    printf("stack underflow\n");
                }
            }
        }
        // PrintList(head);
        // printf("\n");
    }
    return 0;
}

/*headInsert() definiton*/

Nodeptr headInsert(Nodeptr h, Nodeptr top, int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = h;
    h = temp;
    top = top->next;
    return h;
}

/*Delhead() definiton*/

Nodeptr Delhead(Nodeptr h, Nodeptr top)
{
    Nodeptr temp1 = top;
    if(top == NULL){
        printf("stack underflow\n");
        return h;
    }
    if(top!=NULL){
        top = top->next;
        printf("%d\n",temp1->data);
        temp1->next = NULL;
    }
    h = top;
    return h;
}
































