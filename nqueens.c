#include<stdio.h>
int board[100][100];
int qsafe(int n,int row,int col)
{
     int i,j;
     for(i=1;i<=row;i++)
          if(board[i][col]==1)
               return 0;
     for(i=row,j=col;i>=1 && j<=n;i--,j++)
          if(board[i][j]==1)
               return 0;
     for(i=row,j=col;i>=1 && j>=1;i--,j--)
          if(board[i][j]==1)
               return 0;
     return 1;
}
int solvenq(int n,int row)
{
     int i,j;
     if(row>n)
          return 1;
     for(j=1;j<=n;j++)
     {
          if(qsafe(n,row,j)==1)
          {
               board[row][j]=1;
               if(solvenq(n,row+1)==1)
                    return 1;
               board[row][j]=0;
          }
     }
     return 0;
}
void main()
{
     int i,j,n;
     printf("Enter chessboard size \n");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
               board[i][j]=0;
     if(solvenq(n,1)==1)
     {
          printf("The solution is :\n");
          for(i=1;i<=n;i++)
          {
               for(j=1;j<=n;j++)
                    printf(" %d \t",board[i][j]);
               printf("\n");
          }
     }
     else
          printf("No solution \n");
}
