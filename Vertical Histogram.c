#include <stdio.h>
#include <stdlib.h>
int main(){
    char line[101];
    int count[26]={0};
    for (int i=0;i<4;i++){
        if (fgets(line,sizeof(line),stdin)!=NULL){
            for (int j=0;line[j]!='\0';j++){
                if (line[j]>='A' && line[j]<='Z'){
                    count[line[j]-'A']++;
                }
            }
        }
    }
int max=0;
for (int i='A';i<='Z';i++){
    if (count[i-'A']>max)
        max=count[i-'A'];
    }
    for (int j=0;j<max;j++){
        for (int k='A';k<'Z';k++){
            if (count[k-'A']>=max-j){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        if (count['Z'-'A']>=max-j){
            printf("*");
        }
        else{
            printf(" ");
        }
        printf("\n");
    }
for ( int i='A';i<'Z';i++){
    printf("%s ",&i);
}
printf("Z");
return 0;
}