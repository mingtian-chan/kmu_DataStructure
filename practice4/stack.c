#include <stdio.h>
#include <stdlib.h>

#define N 100

// 연결된 표현법이 아니라서 이름 안 써도됨
typedef struct {
  char data[N];
  int top;
}StackType;

void init(StackType *S){
  S-> top = -1;
}

int isEmpty(StackType *S){
  return S->top == -1;
}

int isFull(StackType *S){
  return S->top == N-1;
}

void push(StackType *S, char c){
  if (isFull(S)){
    printf("Full\n");
  }
  else{
    S->top++;
    S->data[S->top] = c;
  }
}

char pop(StackType *S){
  if (isEmpty(S)){
    printf("Empty \n");
    return -1;
  }
  else return S->data[(S->top)--];
}

void print(StackType *S){
  for (int i = 0; i <= S->top; i++){
    printf("%c",  S->data[i]);
  }
  printf("\n");
}

char peek(StackType *S){
  if (isEmpty(S)) {
    printf("Empty\n");
    return -1;
  }
  else return S->data[(S->top)];
}

int main(){
  StackType S;
  init(&S);

  pop(&S);
  push(&S, 'C');
  push(&S, 'A');
  push(&S, 'T');

  print(&S);
  getchar();
  printf("pop: %c\n",pop(&S));
  print(&S);
  getchar();
  printf("peek: %c\n",peek(&S));
  print(&S);
  getchar();
  return 0;
}