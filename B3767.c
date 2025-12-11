#include <stdio.h>//进制转换（递归版）
#include <string.h>
int turnbase (int n,int base)
{
    if (n)
    {
        turnbase(n/base,base);
        int r=n%base;
        putchar(r<10?r+'0':r-10+'A');
    }
    else
        return 0;
    
}
int main(){
    int n,base;
    scanf("%d %d",&n,&base);
    turnbase(n,base);
    return 0;
}