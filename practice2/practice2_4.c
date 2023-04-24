#include <stdio.h>
#include <stdlib.h>

// 피보나치 수열 recursive 하게

int count;

int fib(int n){
  count ++;
  if (n <= 0)
  return 0;
  else if (n == 1)
    return 1;
  else {
    return fib(n-2) + fib(n-1);
  }


}

int main(){
  int n;
  scanf("%d" ,&n);
  printf("%d\n",fib(n));
  printf("%d",count);
  return 0;
}
