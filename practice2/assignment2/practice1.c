#include <stdio.h>
#include <stdlib.h>

int sumOfN(int n){
  if (n==1){
    return 1;
  }
  else{
    return n + sumOfN(n-1);
  }
}

int main(){
  int n;

  printf("%d",sumOfN(n));

  return 0;
}