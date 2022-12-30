#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int pow;
    struct node*next;
};
void linklistTravers(struct node*ptr)
{
    while (ptr!=NULL)
    {
        printf("%dx^%d",ptr->data,ptr->pow);
        ptr=ptr->next;
        if(ptr!=NULL && ptr->data>=0 )
          printf("+"); 
         
    }
    printf("\n");
}
struct node* ADD(struct node*head1,struct node*head2)
{
    struct node* countpt1=head1,*countpt2=head2;
    int c1=0,c2=0;
    while(countpt1!=NULL)
    {
        countpt1=countpt1->next;
       c1+=1;
    }
     while(countpt2!=NULL)
    {
        countpt2=countpt2->next;
       c2+=1;
    }
    struct node* p=head1,*q=head2;
  if (c1<=c2)
  {
      while(p!=NULL)
      {
          while(q!=NULL)
          {
              if(p->pow==q->pow)
                 q->data=q->data+p->data;
                 q=q->next;
          }
          q=head2;
          p=p->next;
      }
      return head2;
  }
  else
  {
       while(q!=NULL)
      {
          while(p!=NULL)
          {
              if(p->pow==q->pow)
                 p->data=q->data+p->data;
                 p=p->next;
          }
          p=head1;
          q=q->next;
      }
      return head1;
  }

}
struct node*Addvalue(struct node*head,int val,int pValue)
{
    if(head==NULL)
      {   struct node*head=(struct node*)malloc(sizeof(struct node));
          head->data=val;
          head->pow=pValue;
          head->next=NULL;
          return head;
      }
      else
      {
          struct node*p=head;
          while(p->next!=NULL)
             p=p->next;
            
            struct node*ptr=(struct node*)malloc(sizeof(struct node));
            ptr->data=val;
            ptr->pow=pValue;
            p->next=ptr;
            ptr->next=NULL;
            return head;
          
      }
}
int main()
{
    struct node* head1=NULL,*head2=NULL;
    int size1,size2,i,j,val,Pval;
    printf("Enter limit for 1st linklist: ");
    scanf("%d",&size1);
    for(i=1;i<=size1;i++)
    {
        printf("Enter value:");
        scanf("%d",&val);
        printf("Enter power:");
        scanf("%d",&Pval);
        head1=Addvalue(head1,val,Pval);
    }
    printf("Enter limit for 1st linklist: ");
    scanf("%d",&size2);
for(i=1;i<=size2;i++)
    {
        printf("Enter value:");
        scanf("%d",&val);
        printf("Enter power:");
        scanf("%d",&Pval);
        head2=Addvalue(head2,val,Pval);
    }
    printf("1st number:");
linklistTravers(head1);
 printf("\n2st number:");
linklistTravers(head2);
printf("ADD:\n");
struct node* res=ADD(head1,head2);
linklistTravers(res);
return 0;
}