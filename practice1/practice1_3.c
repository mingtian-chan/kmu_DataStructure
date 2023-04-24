#include <stdio.h>
#include <stdlib.h>
int main(){
  int score;
  scanf("%d,",&score);
  if(score < 0 || score > 100){
    printf("Wrong Input");
  }

  else
  {
    if(score >= 90 && score <= 100){
      printf("A\n");
    }
    else if (score >=80 && score <90){
      printf("B\n");
    }
    else if (score >=70 && score <80){
      printf("B\n");
    }
    else{
      printf("D\n");
    }
  }
  return 0;
}