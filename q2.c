#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Q {
    int front,back,size,MAX_SIZE;
    int* arrQ;
};

typedef struct Q* Qptr;

Qptr createQ(int n);
void enqueue(Qptr queue, int ele);
void dequeue(Qptr queue);
_Bool isFull(Qptr queue);
_Bool isEmpty(Qptr queue);
void Front(Qptr queue);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l,MAX_SIZE;
        scanf("%d%d",&l,&MAX_SIZE);
        Qptr queue = createQ(MAX_SIZE);
        for(int i=0;i<l;i++)
        {
            char ins[10];
            scanf("%s",ins);
            if(ins[0] == 'e'){
                int num;
                scanf("%d",&num);
                enqueue(queue, num);
            }
            else if(ins[0] == 'd'){
                dequeue(queue);
            }
            else if(ins[0] == 'f'){
                Front(queue);
            }
        }
    }
    return 0;
}


/*createQ() definiton*/

Qptr createQ(int n)
{
    Qptr queue = (Qptr)malloc(sizeof(struct Q));
    queue->MAX_SIZE = n;
    queue->front = 0;
    queue->back = n-1;
    queue->size = 0;
    queue->arrQ = (int*) malloc((queue->MAX_SIZE)* sizeof(int)); 
    return queue; 
}

/*enqueue definition*/
void enqueue(Qptr queue, int ele)
{
    if(isFull(queue)){
        printf("queue overflow\n");
    }
    else{
        queue->back = ((queue->back + 1)%(queue->MAX_SIZE));
        queue->arrQ[queue->back] = ele;
        queue->size++;
    }
}

/*deque definition*/
void dequeue(Qptr queue)
{
    if(isEmpty(queue)){
        printf("queue underflow\n");
    }
    else{
        printf("%d\n",queue->arrQ[queue->front]);
        queue->front = ((queue->front + 1)%(queue->MAX_SIZE));
        queue->size--;
    }
}

/*isFull() definition*/
bool isFull(Qptr queue)
{
    if(queue->size >= queue->MAX_SIZE){
        return true;
    }else{
        return false;
    }
}

/*isEmpty() definition*/
bool isEmpty(Qptr queue)
{
    if(queue->size == 0){
        return true;
    }else{
        return false;
    }
}

/*Front() definition*/
void Front(Qptr queue)
{
    if(isEmpty(queue)){
        printf("queue underflow\n");
    }else{
        int m = queue->arrQ[queue->front];
        printf("%d\n",m);
    }
}


