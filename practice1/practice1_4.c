#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  scanf("%d",&n);
  while(n >= 1){
    printf("%d\n",n%10);
    n /= 10;
  }

  return 0;
}