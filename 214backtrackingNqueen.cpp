#include<iostream>
using namespace std;
#define N 4
void printBoard(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
          cout<<board[i][j]<<" ";
        cout<<endl;
    }

}
bool isSafe(int board[N][N],int row,int col){
int i,j;
 for(i=0;i<col;i++)
     if(board[row][i])    //check this row left side
        return false;
for(i=row,j=col;i>=0 && j>=0;i--,j--)
   if(board[i][j])
   return false;
    for (i=row,j=col;i>= 0 && j>=0;i--,j--)
        if (board[i][j])             //check upper left diagonal
            return false;

for (i=row,j=col;i<N && j>=0;i++,j--)
        if (board[i][j])              //check lower left diagonal
            return false;
return true;
}
bool nQueen(int board[N][N],int col)
{
    if(col>=N)
       return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
        if(nQueen(board,col+1))
           return true;
        

        board[i][col]=0;  //backtrack
        }
    }
    return false;
}
int main(){
    int board[N][N]={{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};

    if(nQueen(board,0))
        printBoard(board);
    else
       cout<<"No solution found";



    return 0;

}