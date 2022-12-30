//Write a C program to calculate sum of digits of a number.
#include<stdio.h>
int main()
{
  int n,i,sum=0;
  printf("Enter number:");
  scanf("%d",&n);
  while(n>0)
  {
    int m=n%10;
    sum=sum+m;
    n=n/10;

  }
  printf("Sum=%d",sum);
  return 0;
} 