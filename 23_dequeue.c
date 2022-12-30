#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int Is_full(struct queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
       return 0;
}
int Is_Empty(struct queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val)
{
    if(Is_full(q))
     printf("\nQueue is Full.");
    else
    {
        q->r++;
     q->arr[q->r]=val;
     printf("Enqued element: %d\n", val);
    } 
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(Is_Empty(q))
    {
        printf("\nQueue is empty.");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
        
    }
     return a; 
}
int main()
{
    struct queue q;
    q.size=3;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,144);
    enqueue(&q,16);
    enqueue(&q,80);
    printf("\nDequeue element:%d",dequeue(&q));
    printf("\nDequeue element:%d",dequeue(&q));
    printf("\nDequeue element:%d",dequeue(&q));
    if(Is_Empty(&q))
      printf("\nQueue is empty now.");
      enqueue(&q,78876);
      //if(Is_full(&q))
      //printf("\nFull Queue");

return 0;
}
