#include <stdio.h>
#include <stdlib.h>

int rFact(int n){
  if (n == 1)
    return 1;
  else{
    return n * rFact(n-1);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  printf("%d",rFact(n));

  return 0;
}