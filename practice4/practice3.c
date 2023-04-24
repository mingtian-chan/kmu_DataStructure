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

int prec(char op){
  switch (op) {
    case '(': case ')':
      return 0;
    case '+': case '-':
      return 1;
    case '*': case '/':
      return 2;
  }
}

void convert(char exp[]){
  StackType S;
  init(&S);

  char c, t; // t : stack의 top
  int n = strlen(exp);

  for(int i = 0; i < n; i++){
    c = exp[i];
    switch(c){
      case '+':
      case '-':
      case '*':
      case '/':
        while(!isEmpty(&S) && prec(c) <= prec(peek(&S)))
          printf("%c",pop(&S));
        push(&S, c);
        break;
      case '(':
        push(&S, c);
        break;
      case ')':
        t = pop(&S);
        while(t != '('){
          printf("%c", t);
          t = pop(&S);
        }
        break;
      default:
        push(&S, c);
        break;
    }
  }
  while (!isEmpty(&S))
    printf("%c",pop(&S));
  printf("\n");

}

// 중위표기식 -> 후위표기식 변환 ( stack에는 연산자가 들어가.

int main(){
  char exp[N];
  scanf("%s",exp);

  convert(exp);
  return 0;
}