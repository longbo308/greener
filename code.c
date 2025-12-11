#include <stdio.h>
#include <string.h>
#define maxline 1000
char pattern[]="ould";
int getline (char s[],int max);
int strindex(char s[],char t[]);
int main(){
    char line[maxline];
    int found=0;
    while (getline(line,maxline)>0)
    {
        if (strindex(line,pattern)>0)
        {
            printf("%s",line);
            found++;
        }
    }
    printf("%d",found);
    return found;
}
int getline (char s[],int max)
{
    int i=0;
    char c;
    while ((c=getchar())!='\n'&&max>0)
    {
        s[i++]=c;
        max--;
    }
    if (c='\n')
    s[i]='\n';
    return i;
}
int strindex(char s[],char t[]){
    int i=0;int j;int k;
    for (i=0;s[i]!='\0';i++)
    {
        for ( k=0,j=i;t[k]==s[j]&&t[k]!='\0';j++,k++);
        if (t[k]=='\0')
        return i;

    }
    return -1;
}
    

