#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int*count=(int*)calloc(n+1,sizeof(int));
    for (int i=0;i<m;i++){
        int people=0;
        scanf("%d",&people);
        count[people]++;
    }
    for (int i=1;i<=n;i++){
        while (count[i]>0){
            printf("%d ",i);
            count[i]--;
        }
    }
    free(count);
    return 0;
}