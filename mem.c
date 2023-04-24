#include <stdio.h>
#include <stdlib.h>

int k;
int y = 0;

int foo(int a, int b) {
  printf("location of a : %p\n",a);
  printf("location of &a : %p\n",&a);
  return a+b;
}
int main(int argc, char *argv[]) {
  int *p = malloc(sizeof(int));
  int x = 3;
  printf("location of code : %p\n",main);
  printf("location of heap : %p\n", malloc(sizeof(int)));
  printf("location of stack(main) : %p\n",&x);
  printf("------------------------------\n");
  x = foo(x, 1);
  printf("location of foo : %p\n",foo);
  printf("location of &y : %p\n",&y);
  printf("location of &k : %p\n",&k);
  printf("location of &p : %p\n", &p);
  printf("location of *p : %p\n",*p);
  printf("location of p : %p\n",p);
  printf("location of x : %p\n",x);
  printf("location of &x : %p\n",&x);

  return 0;
}