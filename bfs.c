#include<stdio.h>
int n,adj[100][100],i,j,n,mark[100],order[100],count=0;
void bfs(int source)
{
     int u,v,q[100],f=-1,r=-1;
     q[++r]=source;
     f=0;
     order[++count]=source;
     mark[source]=1;
     while(f<=r)
     {
          u=q[f++];
          for(v=1;v<=n;v++)
               if(adj[u][v]==1 && mark[v]==0)
               {
                    q[++r]=v;
                    mark[v]=1;
                    order[++count]=v;
               }
     }
}
void main()
{
     int source;
     printf("ENter nummber of nodes \n");
     scanf("%d",&n);
     printf("Enter matrix \n");
     for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
               scanf("%d",&adj[i][j]);
     for(i=1;i<=n;i++)
          mark[i]=0;
     printf("ENter source\n");
     scanf("%d",&source);
     bfs(source);
     for(i=1;i<=n;i++)
          if(mark[i]==0)
               bfs(i);
     printf("The BFS traversal is :\n");
     for(i=1;i<=n;i++)
     printf(" %c \t",64+order[i]);
}
