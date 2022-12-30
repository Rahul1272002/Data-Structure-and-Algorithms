#include<stdio.h>
int min(int x,int y)
{
    if(x<y)
      return x;
    else
       return y;
}
void sort_path(int a[4][4])
{
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(i==j)
            {
                a[i][j]=0;
            }
        else
          {
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);

          }
        }
    }

    for(int l=0;l<4;l++)
    {
      for(int l1=0;l1<4;l1++)
      {
          printf("%d ",a[l][l1]);
      }
      printf("\n");
    }
}
int main()
{
    int arr[4][4]=
    {{0,3,9999,7},
     {8,0,2,9999},
     {5,9999,0,1},
     {2,9999,9999,0},
    };

sort_path(arr);



    return 0;
}