#include <stdio.h>
#include <string.h>
int main(){
    char n[255];
    char result[255];
    int k;
    scanf("%s",n);
    scanf("%d",&k);
    int len=strlen(n);
    int top=0;
    for (int i=0;i<len;i++)
    {
        while (top>0&&k>0&&result[top-1]>n[i])
        {
            top--;
            k--;
        }
        result[top++]=n[i];
    }
    while (k>0)
    {
        top--;
        k--;
    }
    int start=0;
    while (start<top&&result[start]=='0')
    {
        start++;
    }
    if (start==top)
    {
        printf("0\n");
    }
    else
    {
        result[top]='\0';
        printf("%s\n",result+start);
    }
    return 0;
}
