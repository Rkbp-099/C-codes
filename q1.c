#include<stdio.h>

int push(int arrStack[], int top, int size, int num);
int pop(int arrStack[], int top);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,MAX_SIZE,TOP,i;
        scanf("%d%d",&l,&MAX_SIZE);
        int arrStack[MAX_SIZE];
        TOP = -1;
        
        for(i=0;i<l;i++)
        {
            char ins[10];
            scanf("%s",ins);
            if(ins[1] == 'u'){
                int num;
                scanf("%d",&num);
                TOP = push(arrStack, TOP, MAX_SIZE, num);
            }
            else if(ins[0] == 'p'&& ins[1] == 'o'){
                TOP = pop(arrStack, TOP);
            }
            else if(ins[0] == 't'){
                if(TOP <= -1){
                    printf("stack underflow\n");
                }
                else{
                    printf("%d\n",arrStack[TOP]);
                }
            }
        }
    }
    return 0;
}


/* push() definition*/

int push(int arrStack[], int top,int MAX_SIZE, int num)
{
    if(top >= (MAX_SIZE-1)){
        printf("stack overflow\n");
    }
    else{
        top++;
        arrStack[top] = num;    
    }
    return top;
}

/*pop() definition*/

int pop(int arrStack[], int top)
{
    if(top <= -1){
        printf("stack underflow\n");
    }
    else{
        printf("%d\n",arrStack[top]);
        top-- ; 
    }
    return top;
}


