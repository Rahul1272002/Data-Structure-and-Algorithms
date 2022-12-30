#include<stdio.h>
#include"sort_s.h"
#include<stdlib.h>

float knapsack(float *profit,float *weight,int size,int s)
{

float sum=0;
float *x=(float*)calloc(s,sizeof(float));
int cap=size,i;

for( i=0;i<s;i++)
{
   if(weight[i]>cap)
     break;
    else
    {
        x[i]=1.0;
        sum+=profit[i];
        cap-=weight[i];
    }
} 
    if(i<s)
      x[i]=cap/weight[i];
  
sum+=x[i]*profit[i];
for (i=0;i<s;i++)
      printf("%f\t", x[i]);

     

 return sum;
}
int main()
{
    int n;
    printf("Enter size of object:");
    scanf("%d",&n);
    printf("Enter size of bag:");
    int size;
    scanf("%d",&size);
   float *profit,*weight,*ratio,pd,wd,rat;
   profit=(float*)malloc(n*sizeof(float));
   weight=(float*)malloc(n*sizeof(float));
   ratio=(float*)malloc(n*sizeof(float));
   printf("Enter profit and weight:\n");
   for(int i=0;i<n;i++)
   {
       scanf("%f %f",&pd,&wd);
       *(profit+i)=pd;
       *(weight+i)=wd;
   }
    for(int i=0;i<n;i++)
   {
      *(ratio+i)=*(profit+i)/(*(weight+i));
 // printf("Ratio:%f profit:%f weight:%f \n",*(ratio+i),*(profit+i),*(weight+i));
   }

    for(int j=0;j<n;j++)
   {
      printf("Ratio:%f\n",*(ratio+j));

   }

  /* SelectionSort(profit,n);
   SelectionSort(weight,n);
   SelectionSort(ratio,n);*/
  SelectionSort( ratio, weight, profit, n);
printf("\n\n\n");
   for(int j=0;j<n;j++)
   {
      printf("\nRatio:%f\n weight:%f profit:%f",*(ratio+j),*(weight+j),*(profit+j));

   }

printf("\nxiwi:%f",knapsack(profit,weight,size,n));
return 0;
}