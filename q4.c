#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node* Nodeptr;

struct Q{
    Nodeptr front;
    Nodeptr back;
};

typedef struct Q* Qptr;

Qptr createQ();
void enqueue(Qptr queue, int data);
void dequeue(Qptr queue);



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        Qptr queue = createQ();
        int l;
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            char ins[10];
            scanf("%s",ins);
            if(ins[0] == 'e'){
                int ele;
                scanf("%d",&ele);
                enqueue(queue, ele); 
            }
            else if(ins[0] == 'd'){
                dequeue(queue);
            }
            else if(ins[0] == 'f'){
                if(queue->front != NULL){
                    printf("%d\n",(queue->front)->data);
                }
                else{
                    printf("queue underflow\n");
                }
            }
        }
    }
    return 0;
}

/* create Q() definition*/

Qptr createQ()
{
    Qptr queue = (Qptr)malloc(sizeof(struct Q));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

void enqueue(Qptr queue, int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if(queue->front==NULL)
    {
        queue->front = temp;
        queue->back = temp;
    }
    else
    {
        queue->back->next = temp;
        queue->back = temp;
        
    }
}

/*dequeue() definiton*/

void dequeue(Qptr queue)
{
    Nodeptr temp = queue->front;
    if(queue->front == NULL){
            printf("queue underflow\n");
        }
    else{
        queue->front = queue->front->next;
        printf("%d\n",temp->data);
    }
    
    free(temp);
}




