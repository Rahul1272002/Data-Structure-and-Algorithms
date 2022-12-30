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
    int arr[]={16,15,14,7,12,11,5,9,8};
    int size=sizeof(arr)/sizeof(int);
    printarray(arr,size);
   SelectionSort(arr,size);          
   printf("%d\n",arr[0]);
    printarray(arr,size);
    return 0;
}