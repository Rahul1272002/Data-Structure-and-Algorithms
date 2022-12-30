#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int Is_full(struct queue*q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
       return 0;
}
void enqueue(struct queue* q,int val)
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
int main()
{
    struct queue q;
    q.size=100; //2for test 
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q,144);
    enqueue(&q,16);
    enqueue(&q,80);

return 0;
}