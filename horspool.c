#include<stdio.h>
#include<stdlib.h>
int table[120];
void shifttable(char pat[])
{
    int i,j,m;
    m=strlen(pat);
    for(i=0;i<120;i++)
        table[i]=m;
    for(j=0;j<m-1;j++)
    {
        i=pat[j];
        table[i]=m-1-j;
    }
}
int horspool(char text[],char pat[])
{
    int i,j,k,n,m;
    n=strlen(text);
    m=strlen(pat);
    printf("Length of text : %d \n",n);
    printf("Length of pattern : %d \n",m);
    i=m-1;
    while(i<=n)
    {
        k=0;
        while((k<=m)&&(text[i-k]==pat[m-1-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
        {
            j=text[i];
            i+=table[j];
        }
    }
    return(-1);
}
void main()
{
    char text[200],pat[200];
    printf("Enter the text \n");
    gets(text);
    printf("Enter the pattern\n");
    gets(pat);
    shifttable(pat);
    int value;
    value=horspool(text,pat);
    printf("The pattern was found at %d \n",value);
}
