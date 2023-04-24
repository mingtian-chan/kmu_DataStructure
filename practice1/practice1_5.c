#include <stdio.h>
#include <stdlib.h>
int main(){
  int n;
  int evenSum = 0;
  int oddSum = 0;
  scanf("%d",&n);

  for (int i = 1; i <= n; i++){
    if (i % 2 == 0){
      evenSum += i;
    }
    else{
      oddSum += i;
    }
  }
  printf("%d\n",evenSum);
  printf("%d\n",oddSum);



  return 0;
}