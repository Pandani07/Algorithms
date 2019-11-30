#include<stdio.h>
int b[100];
void ss(int n)
{
     int i,j,min,t;
     for(i=0;i<n-1;i++)
     {
          min=i;
          for(j=i+1;j<n;j++)
          {
               if(b[min]>b[j])
                    min=j;
          }
          t=b[min];
          b[min]=b[i];
          b[i]=t;
     }
}
void main()
{
     int i,n;
     printf("Enter array size \n");
     scanf("%d",&n);
printf("Enter telements \n");
for(i=0;i<n;i++)
     scanf("%d",&b[i]);
ss(n);
printf("The sorted array is \n");
for(i=0;i<n;i++)
     printf(" %d \t",b[i]);
}
