#include<stdio.h>
int distance[100],previous[100];
void printpath(int v)
{
     if(previous[v]==-1)
          printf(" %d ",v);
     else
     {
          printpath(previous[v]);
          printf(" --> %d ",v);
     }
}
void main()
{
     int i,j,k,n,u,mark[100],source,weight[100][100],min;
     printf("Enter the number of vertices \n");
     scanf("%d",&n);
     printf("ENter the weight matrix\n");
     for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
               scanf("%d",&weight[i][j]);
     printf("Enter source \n");
     scanf("%d",&source);
     for(i=1;i<=n;i++)
     {
          distance[i]=999;
          mark[i]=0;
          previous[i]=-1;
     }
     distance[source]=0;
     mark[source]=1;
     k=1;
     u=source;
     while(k<n)
     {
          for(i=1;i<=n;i++)
          if(mark[i]==0 && distance[i]>weight[u][i]+distance[u])
          {
               distance[i]=weight[u][i]+distance[u];
               previous[i]=u;
          }
          min=999;
          for(i=1;i<=n;i++)
          if(mark[i]==0 && distance[i]<min)
          {
               min=distance[i];
               u=i;
          }
          mark[u]=1;
          k++;
     }
     printf("The shortest paths from the source vertex %d are \n",source);
     for(i=1;i<=n;i++)
     if(i!=source)
     {
          printf("For vertex %d ",i);
          if(distance[i]==999)
               printf("No path \n");
          else
          {
               printpath(i);
               printf("Distance is %d \n",distance[i]);
          }
     }
}
