/*1.Write a C program to find sum of all even numbers between 1 to n.
2.Write a C program to calculate sum of digits of a number.
3.Write a C program to print Fibonacci series up to n terms.*/

#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Enter  number:");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(i%2==0)
        {
             printf(" %d",i);
           sum=sum+i;
        }
        
    }
    printf("\nSum=%d",sum);
  return 0;
}