#include<stdio.h>
void heapify(int h[],int n)
{
     int i,v,j,k,heap;
     for(i=n/2;i>=1;i--)
     {
          k=i;
          v=h[k];
          heap=0;
          while(!(heap) && (2*k)<n)
          {
               j=2*k;
               if(j<n)
                    if(h[j]<h[j+1])
                         j=j+1;
                    if(v>=h[j])
                         heap=1;
                    else
                    {
                         h[k]=h[j];
                         k=j;
                    }
          }
          h[k]=v;
     }
}
void main()
{
     int h[100],n,i,temp,size;
     printf("ENter array size\n");
     scanf("%d",&n);
     printf("Enter elements \n");
     for(i=1;i<=n;i++)
          scanf("%d",&h[i]);
     heapify(h,n);

     for(i=n;i>=1;i--)
     {
          temp=h[1];
          h[1]=h[i];
          h[i]=temp;
          size=i-1;
          heapify(h,size);
     }
     printf("The sorted elements \n");
     for(i=1;i<=n;i++)
          printf(" %d \t",h[i]);
}
