#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
  int id;
  int money;
}Test;

void makeAccount(Test *T){
  scanf("%d %d", &T->id, &T->money);
  printf("id : %d, money : %d\n", T->id, T->money);
}


void add(Test *T, int amount){
  T->money += amount;
  printf("id : %d, money : %d\n", T->id, T->money);
};


int main(){
  Test a;
  makeAccount(&a);

  int amount;
  scanf("%d",&amount);

  add(&a, amount);
  printf("id : %d, money : %d\n",a.id, a.money);

  return 0;
}