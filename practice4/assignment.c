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

void convert(char infix[N],char postfix[N]) {
  StackType S;
  init(&S);

  char c, t; // t : stack의 top
  int n = strlen(infix);

  int j = 0; // postfix의 index
  for (int i = 0; i < n; i++) {
    c = infix[i];
    switch (c) {
      case '+':
      case '-':
      case '*':
      case '/':
        while (!isEmpty(&S) && prec(c) <= prec(peek(&S))){
          postfix[j] = pop(&S);
          j++;}
        push(&S, c);
        break;
      case '(':
        push(&S, c);
        break;
      case ')':
        t = pop(&S);
        while (t != '(') {
          postfix[j] = t;
          j++;
          t = pop(&S);
        }
        break;
      default:
        push(&S, c);
        break;
    }
  }
  while (!isEmpty(&S)) {
    postfix[j] = pop(&S);
    j++;
  }
  for (int i = 0; i <j; i++){
    printf("%c",postfix[i]);
  }
  printf("\n");
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
  return pop(&S);
}

int main(){
  char infix[N], postfix[N];
  scanf("%s", infix);

  convert(infix, postfix);
  printf("%d\n", evaluate(postfix));

  return 0;
}