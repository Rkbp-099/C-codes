#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    char rol[20];
    struct node* next;
};

typedef struct node* Nodeptr;

struct S{
    Nodeptr top;
};

typedef struct S* Sptr;

struct Cnode{
    Sptr stk;
    struct Cnode* link;
};

typedef struct Cnode* Cnodeptr;

Sptr createS();
void push(Sptr stack, char roll[]);
void pop(Sptr stack);
void printStack(Sptr stk);
void traverse(Cnodeptr chead);
Cnodeptr makeList(Cnodeptr chead, Sptr stk);
bool isEmpty(Sptr stack);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Cnodeptr head = NULL;
        Sptr Mstack = createS();
        Sptr newStack = createS();
        int st, ti;
        scanf("%d%d",&st,&ti);
        for(int i=0;i<st;i++)
        {
            char enroll[20];
            scanf("%s",enroll);
            push(Mstack, enroll);
        }
    
        for(int i=1;i<=ti;i++)
        {
            Sptr newStack = createS();
            head = makeList(head , newStack);
            newStack->top = NULL;
            
        }
        Cnodeptr temp = head;
        
        while(!isEmpty(Mstack))
        {
            char item[20];
            strcpy(item,Mstack->top->rol);
            push(temp->stk, item);
            pop(Mstack);
            temp = temp->link;
            
        }
        
        traverse(head);
    }
    return 0;
}



/* makeList() definition*/

Cnodeptr makeList(Cnodeptr chead, Sptr stk)
{
    Cnodeptr temp = (Cnodeptr)malloc(sizeof(struct Cnode));
    temp->stk = stk;
    temp->link = NULL;
    Cnodeptr temp1 = chead;
    if(chead == NULL)
    {

        chead = temp;
        temp->link = chead; 
        
        return chead;
    }
    else
    {
        while(temp1->link!=chead)
        {
            temp1 = temp1->link;
        }
        temp1->link = temp;
        temp->link = chead;
        
        return chead;
    }
}

/*traverse() definiton*/

void traverse(Cnodeptr chead)
{
    Cnodeptr A = chead;
    printStack(A->stk);
    A = A->link;
    while(A!=chead)
    {
        printStack(A->stk);   
        A = A->link;
    }
}

/*createS() definition*/

Sptr createS()
{
    Sptr stack = (Sptr)malloc(sizeof(struct S));
    stack->top = NULL;
    return stack;
}

/*push() definition*/

void push(Sptr stack, char roll[])
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    strcpy(temp->rol ,roll);
    temp->next = stack->top;
    stack->top = temp;
}

/*pop() definiton*/

void pop(Sptr stack)
{
    Nodeptr temp = stack->top;
    if(stack->top == NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
        stack->top = (stack->top)->next;
        free(temp);
    }
}

/*isEmpty() definition*/
bool isEmpty(Sptr stack)
{
    if(stack->top == NULL){
        return true;
    }else{
        return false;
    }
}

/* printStack() definition*/

void printStack(Sptr stk)
{
    while(!isEmpty(stk))
    {
        printf("%s\n",stk->top->rol);
        pop(stk);
    }
}













