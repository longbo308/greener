#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;   
    if (x > y) return 1;    
    return 0;               
}
int main(){
    int n,m;
    int* a;
    a=(int*)malloc(m*sizeof(int));
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d",a+i);
    }
    qsort(a,m, sizeof(int), compare);
    for (int i=0;i<m;i++){
        printf("%d ",*(a+i));
    }
    free(a);
    return 0;
}