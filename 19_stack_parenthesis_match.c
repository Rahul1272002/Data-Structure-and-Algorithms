#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char*arr;
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
void push(struct stack* ptr,char val)
{ 
    if(Is_Full(ptr))
    printf("Stack Overflow! Value %d can't push in stack\n",val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack* ptr)
{ 
    if(Is_Empty(ptr))
    {
        printf("Stack Underflow!  can't pop in stack\n");
        return -1;
    }
    
    else
    {
     char val=ptr->arr[ptr->top];
       ptr->top--;
       return val;
    }
}
int parenthesis(char * exp)
{   int i;
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(sp,'(');
        }
        else if (exp[i]==')')
        {
            if(Is_Empty(sp))
            {
                return 0;
            }
           pop(sp);
        }
        
    }
    if(Is_Empty(sp))
       return 1;
    else
    return 0;

}

int main()
{   char *exp="(8*(9+6))";
  
   if(parenthesis(exp))
  printf("\nThe parenthesis is match");
  else
   printf("\nThe parenthesis is not match");
  return 0;
   
}