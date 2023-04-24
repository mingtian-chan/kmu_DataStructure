#include <stdio.h>
#include <stdlib.h>

// 작은 순서대로 출력
int eachDigits(int n){
  if (n < 10){
    printf("%d", n);
  }
  else{
    printf("%d\n",n%10);
    eachDigits(n/10);
  }
}

int main(){
  int n;
  scanf("%d",&n);
  eachDigits(n);
  return 0;
}