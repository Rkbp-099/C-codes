#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Cnode{
    char roll[20];
    int marks;
    struct node* link;
};

typedef struct Cnode* Cnodeptr;

struct Snode{
    char rol[20];
    int marks;
    struct Snode* next;
};

typedef struct Snode* Snodeptr;

struct S{
    Snodeptr top;
};

typedef struct S* Sptr;


struct Qnode{
    char data[20];
    int marks;
    struct Qnode* after;
};

typedef struct Qnode* Qnodeptr;

struct Q{
    Qnodeptr front;
    Qnodeptr back;
};

typedef struct Q* Qptr;

Qptr createQ();
void enqueue(Qptr queue, char data[],int num);
void dequeue(Qptr queue);
void printQueue(Qptr que);

Sptr createS();
void push(Sptr stack, char roll[], int num);
void pop(Sptr stack);
void printStack(Sptr stk);
bool isEmpty(Sptr stack);

Cnodeptr tailInsert(Cnodeptr head, char enroll[], int data);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l;
        scanf("%d",&l);
        Sptr inpStack = createS();
        Sptr tmpStack = createS();
        Qptr queue = createQ();
        Cnodeptr head = NULL;
        inpStack->top = NULL;
        tmpStack->top = NULL;
        
        for(int i=0;i<l;i++)
        {
            char enroll[20];
            scanf("%s",enroll);
            int ele;
            scanf("%d",&ele);
            push(inpStack, enroll, ele);
            head = tailInsert(head, enroll, ele);
        }
        
        while(!isEmpty(inpStack))
        {
            char temp[20];
            int tempNum = inpStack->top->marks;
            strcpy(temp, (inpStack->top->rol));
            pop(inpStack);
            while(!isEmpty(tmpStack) && strcmp((tmpStack->top->rol),temp)<0)
            {
                push(inpStack,(tmpStack->top->rol),(tmpStack->top->marks));
                pop(tmpStack);
            }
            push(tmpStack, temp, tempNum);
        }
        
        for(int i=0;i<l;i++)
        {
            enqueue(queue, (tmpStack->top->rol),(tmpStack->top->marks));
            pop(tmpStack);
        }
        
        
        Qptr newQueue = createQ();
        Sptr newStack = createS();
        newQueue->front = NULL;
        newQueue->back = NULL;
        newStack->top = NULL;
        int u=100;
        int d=90;
        while(queue->front!=NULL)
        {
            while(queue->front!=NULL)
            {
                if(queue->front->marks<=u && queue->front->marks >d)
                {
                    push(newStack, queue->front->data, queue->front->marks);
                    dequeue(queue);
                }
                else
                {
                    enqueue(newQueue, queue->front->data, queue->front->marks);
                    dequeue(queue);
                }
            }
            u=u-10;
            d=d-10;
            while(newQueue->front != NULL)
            {
                enqueue(queue, newQueue->front->data, newQueue->front->marks);
                dequeue(newQueue);
            }
            
        }
            
            printStack(newStack);
            printf("\n");
    }
    return 0;
}

/* tailInsert() defintion*/

Cnodeptr tailInsert(Cnodeptr head, char enroll[], int marks)
{
    Cnodeptr temp = (Cnodeptr)malloc(sizeof(struct Cnode));
    temp->marks = marks;
    strcpy(temp->roll, enroll);
    temp->link = NULL;
    Cnodeptr temp1 = head;
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

/* create Q() definition*/

Qptr createQ()
{
    Qptr queue = (Qptr)malloc(sizeof(struct Q));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

/*enqueue() defintion*/

void enqueue(Qptr queue, char data[], int num)
{
    Qnodeptr temp = (Qnodeptr)malloc(sizeof(struct Qnode));
    strcpy(temp->data, data);
    temp->after = NULL;
    temp->marks = num;
    
    if(queue->front==NULL)
    {
        queue->front = temp;
        queue->back = temp;
    }
    else
    {
        queue->back->after = temp;
        queue->back = temp;
        
    }
}

/*dequeue() definiton*/

void dequeue(Qptr queue)
{
    Qnodeptr temp = queue->front;
    if(queue->front == NULL){
            printf("queue underflow\n");
        }
    else{
        queue->front = queue->front->after;
    }
    
    free(temp);
}


/*createS() definition*/

Sptr createS()
{
    Sptr stack = (Sptr)malloc(sizeof(struct S));
    stack->top = NULL;
    return stack;
}

/*push() definition*/

void push(Sptr stack, char roll[], int num)
{
    Snodeptr temp = (Snodeptr)malloc(sizeof(struct Snode));
    strcpy(temp->rol ,roll);
    temp->marks = num;
    temp->next = stack->top;
    stack->top = temp;
}

/*pop() definiton*/

void pop(Sptr stack)
{
    Snodeptr temp = stack->top;
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
        printf("%s ",stk->top->rol);
        printf("%d\n",stk->top->marks);
        pop(stk);
    }
}
/* printQueue() definition*/

void printQueue(Qptr que)
{
    while(!isEmpty(que))
    {
        printf("%s ",que->front->data);
        printf("%d\n",que->front->marks);
        dequeue(que);
    }
}

/*Definition for function PrintList() for printing the Linked List*/

void PrintList(Cnodeptr head)
{
    Cnodeptr A = head;
    while(A!=NULL)
    {
        printf("%s ",A->roll);
        int f = A->marks;
        printf("%d\n",f);
        A = A->link;
        
    }
}
