#include<stdio.h>
void printarray(int* arr,int n)
{  int i;
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
}
void swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int* arr,int n)
{  int i,j,temp;
    for (i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
              {  swap(&arr[j],&arr[j+1]);
                   /*temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;*/
              }
        }
    }
    
}
void Bubblesort(int* arr,int n)
{ int i,j,temp,issorted=0;
    for (i=0;i<n-1;i++)
    {   printf("pass=%d\n",i+1);
        issorted=1;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
              {  swap(&arr[j],&arr[j+1]);
                   /*temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;*/
                   issorted=0;
              }
        }

        if(issorted)
             return;
    }
    
}

int main()
{
    int arr[]={16,15,14,13,12,11,10,9,8};
    //int arr[]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(int);
    printarray(arr,size);
    Bubblesort(arr,size);
    printarray(arr,size);
    
    
    return 0;
}