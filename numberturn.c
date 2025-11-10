#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
void turn_number(char*num,char*result){
    int len=strlen(num);
    int start=0;
    while (start<len&&num[start]=='0') start++;
    if (start==len){
        strcpy(result,"0");
        return;
    }
     len=len-start;
    for (int i=0;i<len;i++){
        result[i]=num[start+len-1-i];
    }
    result[len]='\0';
    int end=0;
    while (end<len&&result[end]=='0') end++;
    if (end==len){
        strcpy(result,"0");
        return;
    }
    if (end>0){
        for (int i=0;i<len-end;i++){
            result[i]=result[i+end];
        }
        result[len-end]='\0';
    }
}
int main(){
    char s[101];
    scanf("%100s",s);
    char result[101];
    char part1[50];
    char part2[50];
    char reversed1[50];
    char reversed2[50];
    if (strchr(s,'.')!=NULL){
        for (int i=0;i<(int)(strchr(s,'.')-s);i++){
                part1[i]=s[i];}
                part1[(int)(strchr(s,'.')-s)]='\0';
        
        for (int i=(int)(strchr(s,'.')-s)+1;i<strlen(s);i++){
                part2[i-((int)(strchr(s,'.')-s)+1)]=s[i];
        }
        part2[strlen(s)-((int)(strchr(s,'.')-s)+1)]='\0';
        turn_number(part1,reversed1);
        turn_number(part2,reversed2);
        int n1=strlen(reversed2);
        while (n1>1&&reversed2[n1-1]=='0') n1--;
        reversed2[n1]='\0';
        if (n1==0){
            strcpy(reversed2,"0");
        }
        printf("%s.%s\n",reversed1,reversed2);
    }
    else if (strchr(s,'/')!=NULL){
        for (int i=0;i<(int)(strchr(s,'/')-s);i++){
                part1[i]=s[i];
        }
        part1[(int)(strchr(s,'/')-s)]='\0';
        for (int i=(int)(strchr(s,'/')-s)+1;i<strlen(s);i++){
                part2[i-((int)(strchr(s,'/')-s)+1)]=s[i];
        }
        part2[strlen(s)-((int)(strchr(s,'/')-s)+1)]='\0';
        turn_number(part1,reversed1);
        turn_number(part2,reversed2);
        printf("%s/%s\n",reversed1,reversed2);
    }
    else if (strchr(s,'%')!=NULL){
        for (int i=0;i<(int)(strchr(s,'%')-s);i++){
                part1[i]=s[i];
        }
        part1[(int)(strchr(s,'%')-s)]='\0';
        turn_number(part1,reversed1);
        printf("%s%%\n",reversed1);
    }
    else {
        turn_number(s,result);
        printf("%s\n",result);
    }
}