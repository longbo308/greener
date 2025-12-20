#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAXL 100

bool samesort(char*a,char*b)
{
    int len_a=strlen(a);
    int len_b=strlen(b);
    int a1[26];
    int b1[26];
    for (int i=0;i<26;i++) 
    a1[i]=b1[i]=0;
    if (len_a!=len_b) return false;
    for (int i=0;i<len_a;i++)
    {
        char temp=a[i];
        a1[temp-'A']++;
    }
    for (int i=0;i<len_b;i++)
    {
        char temp=b[i];
        b1[temp-'A']++;
    }
    int i=0;
    while (i<26 && a1[i]==b1[i]) i++;
    return i==26;
}
int main()
{
    int n;
    scanf("%d",&n);
    char word[n][MAXL];
    for (int i=0;i<n;i++)
    {
        scanf("%s",word[i]);
    }
    int sort=0;
    int* used=(int*)calloc(n,sizeof(int));
    for (int i=0;i<n;i++)
    {
        if (!used[i])
        {
            sort++;
            used[i]=1;
        }
        for (int j=i+1;j<n;j++)
        {
            if (samesort(word[i],word[j]))
            used[j]=1;
        }
    }
    printf("%d",sort);
}