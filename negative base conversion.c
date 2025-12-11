#include <stdio.h>
int main(){
  int n,R,digit=0,temp,a[18];
  scanf("%d %d",&n,&R);
  temp=n;
  while (temp!=0){
    int t=0;
    t=temp%R;
    temp/=R;
    if (t<0)
    {t=t-R;
    temp+=1;}
    a[digit]=t;

    digit++;
  }
  printf("%d=",n);
  for (int i=digit-1;i>=0;i--){
    if (a[i]>=10)
    printf("%c",a[i]-10+'A');
    else
    printf("%d",a[i]);
  }printf("(base%d)",R);
  return 0;
}