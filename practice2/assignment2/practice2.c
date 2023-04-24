#include <stdio.h>
#include <stdlib.h>

// 큰 순서대로 출력
int eachDigits(int n){
  if (n < 10){
    printf("%d\n",n);
  }
  else{
    eachDigits(n / 10);
    printf("%d\n",n%10);
  }
}

int main(){
  int n;
  scanf("%d",&n);
  eachDigits(n);
  return 0;
}