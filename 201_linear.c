#include<stdio.h>

int linearsearch(int arr[],int size,int element)
{ int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==element)
           return i;
    }
    return -1;
}
int main()
{
    int arr[]={1,3,5,6,7,0,2,8,11,19};
    int size=sizeof(arr)/sizeof(int);
    int element;
    printf("Enter search element: ");
    scanf("%d",&element);
    int searchindex=linearsearch(arr,size,element);
    if(searchindex==-1)
       printf("Element not found an array");
       else
        printf("%d no element index %d",element,searchindex);
    return 0;
}