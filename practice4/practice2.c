#include <stdio.h>
#include <stdlib.h>
#include "string.h"

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

int evaluate(char exp[]){
  StackType S;
  init(&S);

  int op1, op2, value;
  char c; // 수식

  int n = strlen(exp);

  for (int i = 0; i < n; i++){
    c = exp[i];

  if (c != '+' && c != '-' && c != '*' && c != '/'){
    value = c - '0'; // 0에 해당하는 아스키값을 뺀거.
    push(&S, value);
}
  else{
    op2 = pop(&S);
    op1 = pop(&S);

    switch(c){
      case '+': {
        push(&S, op1 + op2);
        break;
      }
      case '-': {
        push(&S, op1 - op2);
        break;
      }
      case '*': {
        push(&S, op1 * op2);
        break;
      }
      case '/': {
        push(&S, op1 / op2);
        break;
      }

    }
  }
  }
  pop(&S);
}

// 후위표기식으로 계산 ( stack에는 피연산자가 들어가 )

int main(){
  char exp[N];
  scanf("%s",exp);

  printf("%d\n",evaluate(exp));

  return 0;
}