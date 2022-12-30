#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int stack_Top(struct stack*sp)
{
    return sp->arr[sp->top];
}
int precedence(char ch)
{
    if(ch=='*'||ch=='/')
    return 3;
    else if(ch=='+'||ch=='-')
    return 2;
    else
       return 0;

}
int Isoperator(char ch)
{ 
     if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
     return 1;
     else
     return 0;

}

char * infix_postfix(char* infix)
{  struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
   sp->size=100;
   sp->top=-1;
   sp->arr=(char*)malloc(sp->size*sizeof(char));
   char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
   int i=0,j=0;//i is infix travers and j is append in postfix
    
    while(infix[i]!='\0')
    {
        if(!Isoperator(infix[i]))
        {
            postfix[j]=infix[i];
           i++;
           j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stack_Top(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
           else
           {
               postfix[j]=pop(sp);
              j++;
           }
              
        }
           
    }
    while(!Is_Empty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    
}

int main()
{   char *infix="a-b+t/6";//"A+B*(C+D)/F+D*E";
   printf("parenthesis is %s",infix_postfix(infix));
  
   
  return 0;
   
}