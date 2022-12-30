#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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
int main()
{
    struct stack *s;
    s->size=80;
    s->top=-1;

    s->arr=(int*) malloc(s->size*sizeof(int));
  
 s->arr[0]=7;//push element
  s->top++;    

  if(Is_Empty(s))
  printf("The stack is empty");
  else
   printf("The stack is not empty");
  return 0;
   
}