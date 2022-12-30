#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int*arr;
    int size;
    int top;
};
int Isfull(struct stack*ptr)
{
  if(ptr->top==ptr->size-1)
     return 1;
else
   return 0;
}
int Isempty(struct stack*ptr)
{
    if(ptr->top==-1)
       return 1;
    else 
        return 0;
}
void push(struct stack*ptr,int val)
{
    if(Isfull(ptr))
      printf("Full\n");
    else
       ptr->top++;
       ptr->arr[ptr->top]=val;
       
}
int pop(struct stack*ptr)
{
int a=-1;
    if(Isempty(ptr))
    {
       printf("Empty\n");
       return a; 
    }
     
    else 
    {
        a=ptr->arr[ptr->top];
        ptr->top--;
        return a;
    }
}

int main()
{
    struct stack*s=(struct stack*)malloc(sizeof(struct stack));
   s->size=400;
   s->top=-1;
   s->arr=(int*)malloc(s->size*sizeof(int));
  

  int visited[7]={0,0,0,0,0,0,0};

int a[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
};
int st=4;
push(s,st);
printf("%d ",st);
visited[st]=1;

while (!Isempty(s))
{
    int node=pop(s);
    for(int i=0;i<7;i++)
    {
        if(a[node][i]==1 && visited[i]==0)
        {
            push(s,i);
            visited[i]=1;
            printf("%d ",i);
        }
    }
   
}



return 0;
}