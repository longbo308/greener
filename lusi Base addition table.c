#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10
#define MAX_LEN 3
char table [MAX_N][MAX_N][MAX_LEN];
char letters[MAX_N];
int mapping[256];
int m,n;
bool found_solution=false;
bool check_mapping(){
    for (int i=0;i<m;i++){
        if (mapping[(int)letters[i]]==-1) return false;
    }
    
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            int a=mapping[(int)table[i][0][0]];
            int b=mapping[(int)table[0][j][0]];
            int sum=a+b;
            char*result=table[i][j];
            int len=strlen(result);
            if (sum<m&&sum>=0){
                if(len!=1) return false;
                if(mapping[(int)result[0]]!=sum) return false;

            }else {
                if (len!=2) return false;
                if(mapping[(int)result[0]]!=sum/m) return false;
                if(mapping[(int)result[1]]!=sum%m) return false;
            }
        }
    }
 return true;
}
void generate_permutations(int pos,bool used[]){
    if (found_solution) return;
    if (pos==m){
        if (check_mapping()){
            found_solution=true;
            for (int i=0;i<m;i++){
                printf("%c=%d ",letters[i],mapping[(int)letters[i]]);
                if (i<m-1) printf(" ");
            }
            printf("\n%d\n",m);
    }
        return;
    }
    for (int digit=0;digit<m;digit++){
        if (!used[digit]){
            used[digit]=true;
            mapping[(int)letters[pos]]=digit;
            generate_permutations(pos+1,used);
            used[digit]=false;
            mapping[(int)letters[pos]]=-1;
        }
    }}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%s",table[i][j]);
        }
    }m=n-1;
    for (int i=1;i<n;i++){
        letters[i-1]=table[0][i][0];
    }
    for (int i=0;i<256;i++){
        mapping[i]=-1;
    }
    bool used[MAX_N]={false};
    generate_permutations(0,used);
    if (!found_solution){
        printf("ERROR!\n");

    }
    return 0;
}
