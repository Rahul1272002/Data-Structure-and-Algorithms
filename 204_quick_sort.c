#include<stdio.h>

void printarray(int* arr,int n)
{   int i;
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int low,int high)
{
  int p=arr[low];
  int i=low+1,j=high,temp;
  do
  {
     while (arr[i]<=p)
    {
      i++;
    }
    while (arr[j]>p)
    {
      j--;
    }
    if(i<j)
    {
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }

  } while(i<j);


  temp=arr[low];
  arr[low]=arr[j];
  arr[j]=temp;
  return j;
} 

void quick_sort(int arr[],int low,int high)
{
    int partitionIndex;
   if(low<high)
   {
    partitionIndex=partition(arr,low,high);
    quick_sort(arr,low,partitionIndex-1);
    quick_sort(arr,partitionIndex+1,high);
   }
   
}

int main()
{   
    int arr[100];
    int size,i,low=0;
    printf("Enter size of array:");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
           printf("arr[%d]:",i);
            scanf("%d",&arr[i]);
    }
 
  printf("Before:\n");
    printarray(arr,size);
   quick_sort(arr,low,size-1);
       printf("After:\n");
    printarray(arr,size);
    
    return 0;
}