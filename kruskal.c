#include<stdio.h>
void main()
{
     int a,b,u,v,i,j,k,n,parent[100],cost[100][100],min,sum=0;
     printf("Enter number of vertices \n");
     scanf("%d",&n);
     printf("Enter the cost matrix \n");
     for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
               scanf("%d",&cost[i][j]);
     for(i=1;i<=n;i++)
          parent[i]=0;
     k=1;
     printf("The edges of the minimum cost spanning tree are :\n");
     while(k<n)
     {
          min=999;
          for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
                    if(min>cost[i][j])
                    {
                         min=cost[i][j];
                         a=u=i;
                         b=v=j;
                    }
          while(parent[u])
               u=parent[u];
          while(parent[v])
               v=parent[v];
          if(u!=v)
          {
               printf("Edge %d:%d-->%d, tot cost is %d \n",k,a,b,cost[a][b]);
               sum+=cost[a][b];
               parent[v]=u;
               k++;
          }
          cost[a][b]=cost[b][a]=999;
     }
     printf("The total cost : %d \n",sum);
}
