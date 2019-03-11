#include<stdio.h>
#include<stdbool.h>

struct stack{
    int top,MAX_SIZE;
    int* arrS;
};

typedef struct stack* Sptr;

Sptr createS(int n);
void push(Sptr stack, int num);
bool isEmpty(Sptr stack);
void pop(Sptr stack);
int top(Sptr stack);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int MAX_SIZE;
        scanf("%d",&MAX_SIZE);
        Sptr inpStack = createS(MAX_SIZE);
        Sptr tmpStack = createS(MAX_SIZE);
        inpStack->top = -1;
        tmpStack->top = -1;
        
        for(int i=0;i<MAX_SIZE;i++)
        {
            int ele;
            scanf("%d",&ele);
            push(inpStack, ele);
        }
        
        while(!isEmpty(inpStack))
        {
            int temp = top(inpStack);
            pop(inpStack);
            while(!isEmpty(tmpStack) && top(tmpStack)<temp)
            {
                push(inpStack,top(tmpStack));
                pop(tmpStack);
            }
            push(tmpStack, temp);
        }
        for(int i=0;i<MAX_SIZE;i++)
        {
            int j = top(tmpStack);
            printf("%d ",j);
            pop(tmpStack);
        }
       printf("\n"); 
    }
    return 0;
}

/*createS() definiton*/

Sptr createS(int n)
{
    Sptr stack = (Sptr)malloc(sizeof(struct stack));
    stack->MAX_SIZE = n;
    stack->arrS = (int*) malloc((stack->MAX_SIZE)* sizeof(int)); 
    stack->top = 0;
    
    return stack; 
}

/*push() definition*/

void push(Sptr stack, int num)
{
    if(stack->top >= ((stack->MAX_SIZE)-1)){
        printf("stack overflow\n");
    }
    else{
        (stack->top)++;
        stack->arrS[stack->top] = num;    
    }
}

/*pop() definition*/

void pop(Sptr stack)
{
    if(stack->top <= -1){
        printf("stack underflow\n");
    }
    else{
        //printf("%d\n",stack->arrS[stack->top]);
        (stack->top)-- ; 
    }
}

/* top() definition*/

int top(Sptr stack)
{
    int r = stack->arrS[stack->top];
    return r;
}

/*isEmpty() definition*/
bool isEmpty(Sptr stack)
{
    if(stack->top == -1){
        return true;
    }else{
        return false;
    }
}
