#include<stdio.h>
int wt[100],val[100],v[100][100],n,cap;
int max(int, int);
int knapsack(int i,int j)
{
     int value;
     if(v[i][j]<0)
     {
          if(j<wt[i])
               value=knapsack(i-1,j);
          else
               value=max(knapsack(i-1,j),val[i]+knapsack(i-1,j-wt[i]));
          v[i][j]=value;
     }
     return(v[i][j]);
}
int max(int a,int b)
{
     if(a>b)
          return(a);
     else
          return b;
}
void main()
{
     int i,j;
     printf("Emter the number of items \n");
     scanf("%d",&n);
     printf("Enter the weight and value  of each item \n");
     for(i=1;i<=n;i++)
          scanf("%d%d",&wt[i],&val[i]);
     printf("Enter capacity \n");
     scanf("%d",&cap);
     for(i=0;i<=n;i++)
          for(j=0;j<=cap;j++)
          {
               if(i==0 || j==0)
                    v[i][j]=0;
               else
                    v[i][j]=-1;
          }
     int value=knapsack(n,cap);
     printf("The total value = %d \n",value);
     printf("The matrix is :\n");
     for(i=0;i<=n;i++)
     {
         printf("\n");
         for(j=0;j<=cap;j++)
            printf(" %d \t",v[i][j]);
     }
     j=cap;
     int x[10];
     for(i=0;i<=n;i++)
          x[i]=0;
     for(i=n;i>0;i--)
     {
          if(v[i][j]!=v[i-1][j])
          {
               x[i]=1;
               j=j-wt[i];
          }
     }
     printf("The item set is \n");
     for(i=1;i<=n;i++)
        if(x[i]!=0)
            printf("Item %d \n",i);
}
