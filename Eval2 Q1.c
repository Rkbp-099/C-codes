#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    char name[50];
    char gen[50];
    char city[50];
    char ph[50];
    struct node* next;
};

typedef struct node* Nodeptr;

struct S{
    Nodeptr top;
};

typedef struct S* Sptr;

Sptr createS();
void push(Sptr stack, char name[], char gen[], char city[], char ph[]);
void pop(Sptr stack);
void printStack(Sptr stk);
bool isEmpty(Sptr stack);



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        Sptr stack = createS();
        stack->top = NULL;
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
            
            push(stack, name, gen, city, ph);
        }
        
        printStack(stack);
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

void push(Sptr stack, char name[], char gen[], char city[], char ph[])
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    strcpy(temp->name ,name);
    strcpy(temp->gen ,gen);
    strcpy(temp->city ,city);
    strcpy(temp->ph ,ph);
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


/* printStack() definition*/

void printStack(Sptr stk)
{
    while(!isEmpty(stk))
    {
        printf("%s ",stk->top->name);
        printf("%s ",stk->top->gen);
        printf("%s ",stk->top->city);
        printf("%s\n",stk->top->ph);
        pop(stk);
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
    












