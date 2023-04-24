#include <stdio.h>
#include <stdlib.h>

double iPower(double x, int n) {
  int i;
  double result = 1.0;

  for (i = 0; 1 < n; i++) {
    result = result * x;
    return result;
  }
}

double rPower(double x, int n){
  if (n==0) return 1;
  else if ((n%2) == 0)
    return rPower(x*x, n/2);
  else return x* rPower(x*x,(n-1)/2);
}

int main(){
  double x;
  int n;
  scanf("%lf %d",&x,&n);
  return 0;
}