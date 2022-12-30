#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};
int Is_Empty(struct stack* ptr)
{   if(ptr->top==-1)
     {
         return 1;
     }
     else{
         return 0;
     }

}
int Is_Full(struct stack* ptr)
{   if(ptr->top==ptr->size-1)
     {
         return 1;
     }
     else{
         return 0;
     }

}
void push(struct stack* ptr,int val)
{ 
    if(Is_Full(ptr))
    printf("Stack Overflow! Value %d can't push in stack\n",val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack* ptr)
{ 
    if(Is_Empty(ptr))
    {
        printf("Stack Underflow!  can't pop in stack\n");
        return -1;
    }
    
    else
    {
       int val=ptr->arr[ptr->top];
       ptr->top--;
       return val;
    }
}
int peek(struct stack*sp,int i)
{
    int arr_ind=sp->top-i+1;
    if(arr_ind<0)
    {   
        printf("Invalid\n");
        return -1;
    }
    else
     return sp->arr[arr_ind];
}
int main()
{
    struct stack *sp=(struct stack*) malloc(sizeof(struct stack));
    
    sp->size=10;
    sp->top=-1;
    sp->arr=(int*) malloc(sp->size* sizeof(int));
    printf("Stack has been creating.");
printf("Before:\n");
    printf("\nFull:%d",Is_Full(sp));
    printf("\nEmpty:%d", Is_Empty(sp));
printf("\nAfter:\n");

push(sp,57);
push(sp,57);
push(sp,57);
push(sp,22);
push(sp,97);
push(sp,67);
push(sp,59);
push(sp,52);
push(sp,57);
push(sp,47);

    printf("\nFull:%d",Is_Full(sp));
    printf("\nEmpty:%d", Is_Empty(sp));
    
       
     for(int j=1;j<=sp->top+1;j++)
     printf("\nThe value of position %d is %d",j,peek(sp,j));
    return 0;
}