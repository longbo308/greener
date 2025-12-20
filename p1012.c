#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 25
int cmp(const void *a,const void *b){
    char str1[MAX_LEN],str2[MAX_LEN];
    sprintf(str1,"%d",**(int**)a);
    sprintf(str2,"%d",**(int**)b);
    char ab[MAX_LEN*2],ba[MAX_LEN*2];
    strcpy(ab,str1);
    strcat(ab,str2);
    strcpy(ba,str2);
    strcat(ba,str1);
    return strcmp(ba,ab);
}
int main(){
    int n;
    scanf("%d",&n);
    int**arr=(int**)calloc(n,sizeof(int*));
    for (int i=0;i<n;i++)
    {
        *(arr+i)=(int*)calloc(1,sizeof(int));
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",arr[i]);
    }
    qsort(arr,n,sizeof(int*),cmp);
    for (int i=0;i<n;i++)
    {
        printf("%d",*arr[i]);
    }
    for (int i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}