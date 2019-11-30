#include<stdio.h>
int n,adj[100][100],i,j,n,mark[100],order[100],count=0;
void dfs(int u)
{
     int v;
     order[++count]=u;
     mark[u]=1;
     for(v=1;v<=n;v++)
          if(adj[u][v]==1 && mark[v]==0)
               dfs(v);
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
     dfs(source);
     for(i=1;i<=n;i++)
          if(mark[i]==0)
               dfs(i);
     printf("The DFS traversal is :\n");
     for(i=1;i<=n;i++)
     printf(" %c \t",64+order[i]);
}
