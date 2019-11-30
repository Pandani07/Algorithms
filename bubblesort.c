#include<stdio.h>
#include<stdlib.h>
int a[100];
void bs(int n)
{
     int i,j,t;
     for(i=0;i<n-1;i++)
          for(j=0;j<n-i-1;j++)
               if(a[j]>a[j+1])
                    {
                         t=a[j];
                         a[j]=a[j+1];
                         a[j+1]=t;
                    }
}

void main()
{
     int i,n,ch;
     printf("Enter the size of array\n");
               scanf("%d",&n);
                         printf("Enter telements \n");
                         for(i=0;i<n;i++)
                              scanf("%d",&a[i]);
                         bs(n);
                         printf("The sorted array is \n");
                         for(i=0;i<n;i++)
                              printf(" %d \t",a[i]);
}
