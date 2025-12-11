#include <stdio.h>
#include <stdlib.h>
int main(){
    char a[33];
    char temp[9];
    int flag=0;
    int result=0;
    scanf("%s",&a);
    a[32]='\0';
    for (int i=0;a[i]!='\0';i=i+8)
    {
        for (int j=i;j<i+8;j++)
            temp[j-i]=a[j];
        temp[8]='\0';
        flag++;
        for (int k=0;k<8;k++)
        {
            result=result*2+(temp[k]-'0');
        }
        printf("%d%c",result,flag==4?'\n':'.');
        result=0;
    }
}