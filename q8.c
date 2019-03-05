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

Sptr createS();
void push(Sptr stack, char roll[]);
void pop(Sptr stack);
bool isEmpty(Sptr stack);
void printStack(Sptr stk);


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
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
        for(int i=0;i<(st/ti);i++)
        {
            for(int i=0;i<ti;i++)
            {
                push(newStack,(Mstack->top->rol));
                pop(Mstack);
            }
            printStack(newStack);
        }
        Sptr newStack2 = createS();
        while(Mstack->top!= NULL)
        {
            push(newStack2, Mstack->top->rol);
            Mstack->top = Mstack->top->next;
        }
        printStack(newStack2);
    }
    return 0;
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













