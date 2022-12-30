#include<stdio.h>
void printarray(int* arr,int n)
{  int i;
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");
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


int main()
{   
    int arr[]={12,54,65,7,23,9};
    int size=sizeof(arr)/sizeof(int);
    printarray(arr,size);
  InsertSort(arr,size);
    printarray(arr,size);
    return 0;
}