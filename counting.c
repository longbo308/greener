#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char**results=(char**)malloc(n*sizeof(char*));
    for (int k=0;k<n;k++){
        results[k]=(char*)malloc(100*sizeof(char));
    }
    int*arr=(int*)malloc((n)*sizeof(int));
    char temp[10]={'\0'};
    for (int i=0;i<n;i++){
        char op[10];
        scanf("%s",op);
        if (op[0]=='a'||op[0]=='b'||op[0]=='c'){
            int x,y;
            scanf("%d %d",&x,&y);
            if (op[0]=='a'){
            arr[i]=(sprintf(results[i],"%d+%d=%d",x,y,x+y));
        }
        if (op[0]=='b'){
            arr[i]=(sprintf(results[i],"%d-%d=%d",x,y,x-y));

        }
        if (op[0]=='c'){
            arr[i]=(sprintf(results[i],"%d*%d=%d",x,y,x*y));

        }
        temp[0]=op[0];
        }
        else {
            int x=atoi(op);
            op[0]=temp[0];
            int y;
            scanf("%d",&y);
            if (op[0]=='a'){
            arr[i]=(sprintf(results[i],"%d+%d=%d",x,y,x+y));

        }if (op[0]=='b'){
            arr[i]=(sprintf(results[i],"%d-%d=%d",x,y,x-y));

        }
    if (op[0]=='c'){
            arr[i]=(sprintf(results[i],"%d*%d=%d",x,y,x*y));

        }
        }
    }
      for (int j=0;j<n;j++){
        printf("%s\n",results[j]);
        printf("%d\n",arr[j]);
      }
      free(arr);
      free(results);
    return 0;
}