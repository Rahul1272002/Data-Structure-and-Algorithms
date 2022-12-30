//binarysearch
#include<stdio.h>

int binarysearch(int arr[],int size, int element)
{
    int low,mid,high;
    low=0;
    high=size-1;

 while(low<=high)
  {
    mid=(low+high)/2;                                                     
                                 
    if(arr[mid]==element)         
    {  
        return mid;
    }
       if(arr[mid]<element)
      {
          low=mid+1;
      }
      else
      {
          high=mid-1;            
      }
 }
 return -1;
}
int main()
{
    int arr[]={3,5,6,7,8,9,10,11,14,16};
    int size=sizeof(arr)/sizeof(int);
    int element;
    printf("Enter search element: ");
    scanf("%d",&element);
    int searchindex=binarysearch(arr,size,element);
    if(searchindex==-1)
    printf("Not found element");
    else
    printf("%d no element index %d",element,searchindex);
    return 0;
}