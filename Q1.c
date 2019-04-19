#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
Nodeptr Insert(Nodeptr head, int data);
bool isEmpty(Qptr queue);
void BFS(int s, int size, Nodeptr adj_li[]);



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,b;
        scanf("%d%d",&n,&b);
        Nodeptr adj_li[n];
        for(int i=0;i<n;i++)
        {
            adj_li[i] = NULL;
        }

        for(int i=0;i<b;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj_li[x] = Insert(adj_li[x], y);
        }

        BFS(0, n, adj_li);

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

/*Definition for function tailInsert() for creating the Linked List by inserting node at tail*/

Nodeptr Insert(Nodeptr head, int data)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    temp->next = head;
    head = temp;    

    return head;
    
}

/*BFS() definition*/
void BFS(int s, int size, Nodeptr adj_li[])
{
    int visited[size];
    int ans[size];

    for(int i=0;i<size;i++)
    {
        ans[i] = -1;
        visited[i] = 0; 
    }

    Qptr queue = createQ();

    visited[s] = 1;
    enqueue(queue, s);
    int m = (queue->front)->data;
    ans[m] = 0;

    while(!isEmpty(queue))
    {
        m = (queue->front)->data;
        dequeue(queue);

        Nodeptr temp = adj_li[m];
        while(temp!= NULL) 
        { 
            if (visited[temp->data] == 0) 
            { 
                ans[temp->data] = ans[m] + 1;
                visited[temp->data] = 1; 
                enqueue(queue, temp->data); 
            } 
            
            temp = temp->next;
        } 
    }
    for(int i=0;i<size;i++)
    {
        printf("%d\n",ans[i]);
    }
}


/*enquque() definiton*/

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
        //printf("%d\n",temp->data);
    }
    
    free(temp);
}

/*isEmpty() definition*/
bool isEmpty(Qptr queue)
{
    if(queue->front == NULL){
        return true;
    }else{
        return false;
    }
}





