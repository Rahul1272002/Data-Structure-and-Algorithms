#include<stdio.h>
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
                  
              }
        }
    }
    
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
  } while (i<j);
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
void InsertSort(int* arr,int n)
{  int i,j,key;

    for (i=1;i<=n-1;i++)
    {   key=arr[i];
         j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}
void SelectionSort(int* arr,int n)
{   int i,j,min;

    for (i=0;i<n-1;i++)
    {   min=i;
        for(j=i+1;j<n;j++)
        {   
            if(arr[j]<arr[min])
                 min=j;
        }
        swap(&arr[i],&arr[min]);

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
  printf("\nEnter 1 for Bubble sort\nEnter 2 for Selection sort\nEnter 3 for Insertion sort\nEnter 4 for Quick sort");
  printf("\nEnter choice:");
  int ch;
  scanf("%d",&ch);
  switch (ch)
  {
  case 1:
     printf("After:\n");
    printarray(arr,size);
   bubblesort(arr,size);
    printf("Before:\n"); 
    printarray(arr,size);

    break;
  case 2:
   printf("After:\n");
    printarray(arr,size);
   SelectionSort(arr,size);
    printf("Before:\n"); 
    printarray(arr,size);

  break;
  case 3:
   printf("After:\n");
    printarray(arr,size);
   InsertSort(arr,size);
    printf("Before:\n"); 
    printarray(arr,size);
    break;
    case 4:
    printf("After:\n");
    printarray(arr,size);
   quick_sort(arr,low,size-1);
    printf("Before:\n"); 
    printarray(arr,size);
    break;
  default:
    break;
  }
  
    return 0;
}