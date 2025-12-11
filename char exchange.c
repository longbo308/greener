#include <stdio.h>
#include <math.h>
int main(){
    int i=0;
    int digit=0;
    int arr[10];
    int arr1[10];
    while ((arr[i]=getchar())!='\n'){
        if(arr[i]>='0'&&arr[i]<='9'){
            arr[digit]=arr[i]-'0';
            digit++;
        }
        i++;
    }int sum=0;
    for (int j=0;j<digit;j++){
        sum+=arr[j]*pow(10,digit-j-1);
    }
    printf("%d\n",sum);
    return 0;
}