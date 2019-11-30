#include<stdio.h>
void main()
{
     int u,v,min,k,i,j,n,wt[100][100],mark[100];
     printf("Enter the number of nodes\n");
     scanf("%d",&n);
     printf("Enetr the weight matrix\n");
     for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
               scanf("%d",&wt[i][j]);
     printf("Enter source \n");
     int source;
     scanf("%d",&source);
     for(i=1;i<=n;i++)
          mark[i]=0;
     mark[source]=1;
     k=1;
     int sum=0;
     while(k<n)
     {
          min=999;
          for(i=1;i<=n;i++)
               if(mark[i]==1)
                    for(j=1;j<=n;j++)
                         if(mark[j]==0 && min>wt[i][j])
                         {
                              min=wt[i][j];
                              u=i;
                              v=j;
                         }
          mark[v]=1;
          sum+=wt[u][v];
          printf("Edge %d:%d-->%d\n",k++,u,v);
     }
     printf("Thhe weight is %d \n",sum);
}
