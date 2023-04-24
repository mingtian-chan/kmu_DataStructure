#include <stdio.h>
#include <stdlib.h>

// 하노이의 탑 recursive
// n : 원반의 개수
// from : 시작 지점
void hanoi(int n, char from, char tmp, char to){
  if(n == 1){
    printf("Disk %d : Move from %c to %c. \n",n,from, to);
  }
  else{
    hanoi(n-1, from, to, tmp);
    printf("Disk %d : Move from %c to %c. \n",n,from, to);
    hanoi(n-1, tmp, from, to);
  }
}


int main(){
  hanoi(4, 'A', 'B', 'C');
  return 0;
}