#include<stdio.h>
#include<stdlib.h>
int part(int a[100],int l,int h)
{
     int i=l,p=l,j=h,temp;
     while(i<j)
     {
          while(a[i]<=a[p] && i<h)
               i++;
          while(a[j]>a[p] && j>l)
               j--;
          if(i<j)
          {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
          }
     }
     temp=a[p];
     a[p]=a[j];
     a[j]=temp;
     return j;
}
void quicksort(int a[100],int l,int h)
{
     if(l<h)
     {
          int p=part(a,l,h);
          quicksort(a,l,p-1);
          quicksort(a,p+1,h);
     }
}
void main()
{
     int i,n,a[100];
     printf("Enter the size of array\n");
     scanf("%d",&n);
     printf("Enter telements \n");
     for(i=0;i<n;i++)
          scanf("%d",&a[i]);
     quicksort(a,0,n-1);
     printf("The sorted array is \n");
     for(i=0;i<n;i++)
          printf(" %d \t",a[i]);
}
