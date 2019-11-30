#include<stdio.h>
int r[100][100];
void war(int n)
{
     int i,j,k;
     for(k=0;k<n;k++)
          for(i=0;i<n;i++)
               for(j=0;j<n;j++)
                    if(r[i][k]==1 && r[k][j]==1)
                         r[i][j]=1;
}
void main()
{
     int i,j,n;
     printf("ENter the size of matrx \n");
     scanf("%d",&n);
     printf("Enter the distance matrox\n");
     for(i=0;i<n;i++)
          for(j=0;j<n;j++)
               scanf("%d",&r[i][j]);
     war(n);
     printf("The transitive x=closure is \n");
     for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
               printf(" %d \t",r[i][j]);
          printf("\n");
     }
}
