#include<stdio.h>
#include<stdlib.h>
int jobseq(int *profit,int*deadlines,int s,int a_size)
{
     int *store=(int*)calloc((s+1),sizeof(int));

     int sum=0;

     for(int i=0;i<a_size;i++)
     {   int v=deadlines[i];
       for(int j=v-1;j>=0;j--) 
       {
           if(store[j]==0)
           {  //printf("\n%d  ",j);
               store[j]=profit[i];
               sum+=profit[i];
               break;
           }
       }
         
     }
//printf("store[2]:%d store[1]:%d store[0]:%d",store[2],store[1],store[0]);
  return sum;

}
int main()
{  int size;
printf("Enter job size:");
scanf("%d",&size);
    int*profit,*deadilines;
    profit=(int*)malloc(size*sizeof(int));
    deadilines=(int*)malloc(size*sizeof(int));
    printf("Enter profits and deadlines:");

    for(int i=0;i<size;i++)
    scanf("%d %d",&profit[i],&deadilines[i]);

 int s_size=deadilines[0];


int res=jobseq(profit,deadilines,s_size,size);
printf("\nprofit:%d",res);

return 0;

}