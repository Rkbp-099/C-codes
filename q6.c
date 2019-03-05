#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct stack1{
    int top,MAX_SIZE;
    int* arrS;
};

typedef struct stack1* S1ptr;

struct stack2{
    int top,MAX_SIZE;
    char* arrS;
};

typedef struct stack2* S2ptr;

S1ptr createS1(int n);
void push1(S1ptr stack1, int num);
bool isEmpty1(S1ptr stack1);
void pop1(S1ptr stack1);
int top1(S1ptr stack1);

S2ptr createS2(int n);
void push2(S2ptr stack2, char num);
bool isEmpty2(S2ptr stack2);
void pop2(S2ptr stack2);
char top2(S2ptr stack2);

int compute(char expr[]);
int pre(char ope);
int calculate(int m, int n, char ope);

bool isVal(char inp);


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char expr[1000];
        scanf("%s",expr);
        int res = compute(expr);
        printf("%d\n",res);
    }
    return 0;
}


/*compute() definiton*/

int compute(char expr[])
{ 
    int i;
    S1ptr operands = createS1(1000); 
    S2ptr signs = createS2(1000); 
    for(i=0;i<strlen(expr);i++)
    { 
        if(expr[i] == ' ')
        { 
            continue; 
        }
        else if(expr[i] == '(')
        { 
            push2(signs,expr[i]); 
        } 
        else if(isVal(expr[i])){ 
            int opr = 0; 
            while(i < strlen(expr) && isVal(expr[i])) 
            { 
                opr = (opr*10)+(expr[i]-'0'); 
                i++; 
            } 
            i--;
            push1(operands,opr); 
        } 
        else if(expr[i] == ')') 
        { 
            while(!isEmpty2(signs) && top2(signs) != '(') 
            { 
                int opr2 = top1(operands); 
                pop1(operands); 
                int opr1 = top1(operands); 
                pop1(operands); 
                char ope = top2(signs); 
                pop2(signs); 
                push1(operands,calculate(opr1, opr2, ope)); 
            } 
            pop2(signs); 
        } 
        else
        { 
            while(!isEmpty2(signs) && pre(top2(signs))>=pre(expr[i]))
            { 
                int opr2 = top1(operands); 
                pop1(operands);
                int opr1 = top1(operands); 
                pop1(operands); 
                char ope = top2(signs); 
                pop2(signs); 
                push1(operands,calculate(opr1, opr2, ope));  
            } 
            push2(signs,expr[i]); 
        } 
    }
    
    while(!isEmpty2(signs))
    { 
        int opr2 = top1(operands); 
        pop1(operands); 
        int opr1 = top1(operands);
        pop1(operands); 
        char ope = top2(signs); 
        pop2(signs);  
        push1(operands,calculate(opr1, opr2, ope));   
    } 
    return top1(operands);
} 

/*pre() definition*/

int pre(char ope){ 
    if(ope == '+' || ope == '-'){
        return 1;
    } 
    if(ope == '*' || ope == '/'){
        return 2;
    }
    return 0; 
} 

/*calculate() definition*/
  
int calculate(int m, int n, char ope){ 
    switch(ope)
    { 
        case '+': 
            return (m+n); 
        case '-': 
            return (m-n); 
        case '/': 
            return (m/n); 
        case '*': 
            return (m*n);
    } 
} 
  
/*createS1() definiton*/

S1ptr createS1(int n)
{
    S1ptr stack1 = (S1ptr)malloc(sizeof(struct stack1));
    stack1->MAX_SIZE = n;
    stack1->arrS = (int*) malloc((stack1->MAX_SIZE)* sizeof(int)); 
    stack1->top = 0;
    
    return stack1; 
}

/*createS2() definiton*/

S2ptr createS2(int n)
{
    S2ptr stack2 = (S2ptr)malloc(sizeof(struct stack2));
    stack2->MAX_SIZE = n;
    stack2->arrS = (char*) malloc((stack2->MAX_SIZE)* sizeof(char)); 
    stack2->top = 0;
    
    return stack2; 
}

/*push1() definition*/

void push1(S1ptr stack1, int num)
{
    if(stack1->top >= ((stack1->MAX_SIZE)-1)){
        printf("stack overflow\n");
    }
    else{
        (stack1->top)++;
        stack1->arrS[stack1->top] = num;    
    }
}

/*push2() definition*/

void push2(S2ptr stack2, char num)
{
    if(stack2->top >= ((stack2->MAX_SIZE)-1)){
        printf("stack overflow\n");
    }
    else{
        (stack2->top)++;
        stack2->arrS[stack2->top] = num;    
    }
}

/*pop1() definition*/

void pop1(S1ptr stack1)
{
    if(stack1->top <= -1){
        printf("stack underflow\n");
    }
    else{
        //printf("%d\n",stack->arrS[stack->top]);
        (stack1->top)-- ; 
    }
}

/*pop2() definition*/

void pop2(S2ptr stack2)
{
    if(stack2->top <= -1){
        printf("stack underflow\n");
    }
    else{
        //printf("%d\n",stack->arrS[stack->top]);
        (stack2->top)-- ; 
    }
}

/* top1() definition*/

int top1(S1ptr stack1)
{
    int r = stack1->arrS[stack1->top];
    return r;
}

/* top() definition*/

char top2(S2ptr stack2)
{
    char r = stack2->arrS[stack2->top];
    return r;
}

/*isEmpty1() definition*/
bool isEmpty1(S1ptr stack1)
{
    if(stack1->top == -1){
        return true;
    }else{
        return false;
    }
}

/*isEmpty2() definition*/
bool isEmpty2(S2ptr stack2)
{
    if(stack2->top == -1){
        return true;
    }else{
        return false;
    }
}

/*isVal() definition*/
bool isVal(char inp)
{
    int k = inp;
    if(k>=48 && k<=57){
        return true;
    }
    else{
        return false;
    }
}








