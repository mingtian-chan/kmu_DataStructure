#include <stdio.h>
#include <stdlib.h>

int Max(int arr[], int n){
  if (n == 0){
    return arr[0];
  }
  else{
    int max = Max(arr, n - 1);
    if (arr[n-1] > max){
      return arr[n-1];
    }
    else{
      return max;
    }
  }
}

int main(){
  int n;
  int arr[20] = {0};
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("%d\n",Max(arr,n));
  return 0;
}