#include<stdio.h>
#include<stdlib.h>
struct circular_queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int Is_full(struct circular_queue *q)
{
    if((q->r+1)%q->size==q->f)
    {
        return 1;
    }
       return 0;
}
int Is_Empty(struct circular_queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct circular_queue *q,int val)
{
    if(Is_full(q))
     printf("\nQueue is Full.");
    else
    {
     q->r=(q->r+1)%q->size;
     q->arr[q->r]=val;   
     printf("Enqued element: %d\n", val);
    } 
}
int dequeue(struct circular_queue *q)
{
    int a=-1;
    if(Is_Empty(q))
    {
        printf("\nQueue is empty.");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        
    }
     return a; 
}
int main()
{
    struct circular_queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,144);
    enqueue(&q,16);
    enqueue(&q,80);
    enqueue(&q,60);
    printf("\nDequeue element:%d",dequeue(&q));
    printf("\nDequeue element:%d",dequeue(&q));
    printf("\nDequeue element:%d\n",dequeue(&q));
    enqueue(&q,89);
    enqueue(&q,44);
    enqueue(&q,843);
    if(Is_Empty(&q))
      printf("\nQueue is empty now.");
    if(Is_full(&q))
      printf("\nFull Queue");
      printf("%d  %d",q.f,q.r);

return 0;
}