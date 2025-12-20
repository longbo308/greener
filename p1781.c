#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int sort(char**s,int n)
{
    int len_s[n];
    for (int i=0;i<n;i++)
    {
        len_s[i]=strlen(s[i]);
    }
    int max=0;int i;
    int buffer[n];int count=0;
    for (i=0;i<n;i++)
    {
        if (len_s[i]>max)
        {
            count=0;
            max=len_s[i];
            buffer[0]=i;
            continue;
        }
        if (len_s[i]==max)
        {
            count++;
            buffer[count]=i;
        }
    }
    if (!count)
    {
        return buffer[0];
    }
    else 
    {
        for (int j=0;j<1;j++)
        {
            for (int k=j+1;k<count;k++)
            {
                if (strcmp(s[buffer[k]],s[buffer[j]])>0)
                {
                    int temp;
                    temp=buffer[k];
                    buffer[k]=buffer[j];
                    buffer[j]=temp;
                }
            }
        }
        return buffer[0];
    }

}
int main(){
    int n;
    scanf("%d",&n);
    char**a=(char**)calloc(n,sizeof(char*));
    for (int i=0;i<n;i++)
    {
        a[i]=(char*)calloc(101,sizeof(char));
    }
    for (int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    int index=sort(a,n);
    int i=0;
    printf("%d\n",index+1);
    while ((a[index][i])!='\0')
    {
        putchar(a[index][i++]);
    }

}