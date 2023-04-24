#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  if (isEmpty(S)){
    printf("Empty\n");
    return -1;
  }
  else return S->data[(S->top)];
}

int check(StackType *S, char str[]){
  char c, t; // 현재문자, top문자
  int n = strlen(str); // 문자열의 개수를 셈

  for (int i = 0; i < n; i++){
    c = str[i];
    if (c == '(' || c == '{' || c == '[')
      push(S, c);
    else if (c == ')' || c == '}' || c == ']'){
      if (isEmpty(S))
        return 0;
      else{
        t = pop(S);
        if((t == '(' && c != ')')
        || (t == '{' && c != '}')
        || (t == '[' && c != ']'))
          return 0;
      }
    }
  }
  return isEmpty((S));
}

int main(){
  StackType S;
  init(&S);
  char str[N];
  scanf("%s",str);
  // scanf 는 공백문자를 인식하지못함.
  if (check(&S,str))
    printf("OK");
  else
    printf("NO");
  return 0;
}