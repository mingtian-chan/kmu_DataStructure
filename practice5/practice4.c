#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10

typedef char element;

typedef struct{
  element data[N];
  int front;
  int rear;
}ListType;

void init(ListType *D){
  D-> front = D -> rear = 0;
}
// size로 modulation 해야함.
int isFull(ListType *D){
  return D-> front == (D-> rear +1) % N;
}

int isEmpty(ListType *D){
  return D-> front == D->rear;
}

void addFront(ListType *D, element e){
  if (isFull(D))
    printf("Full\n");
  else{
    D->front = (D->front + N - 1) % N;
    D-> data[D->front] = e;
  }
}

void addRear(ListType *D, element e){
  if (isFull(D))
    printf("Full\n");
  else{
    D-> rear = (D->rear + 1) % N;
    D-> data[D->rear] = e;
  }
}

element deleteFront(ListType *D){
  if (isEmpty(D)){
    printf("Empty\n");
    return 0;
  }
  D->front = (D->front + 1) % N;
  return D->data[D->front];
}

element deleteRear(ListType *D){
  if (isEmpty(D)){
    printf("Empty\n");
    return 0;
  }
  int pos = D->rear;
  D->rear = (D-> rear + N - 1) % N;
  return D->data[pos];
}

element peek(ListType *D){
  if (isEmpty(D)){
    printf("Empty\n");
    return 0;
  }
  return D->data[(D->front + 1) % N];
}

element getRear(ListType *D){

}

void print(ListType *D){
  printf("Front : %d - Rear : %d\n",D->front, D-> rear);
  int i = D-> front;

  while(i != D-> rear){
    i = (i+1) % N;
    printf("[%c]", D->data[i]);
  }

  printf("\n");
}

int getCount(ListType *D){
  int count = D->rear - D->front;
  if (count < 0)
    count += N;

  return count;
}


// 데큐
int main(){
  ListType D;
  init(&D);

  char str[N];

  scanf("%s", &str);

  for (int i = 0; i < strlen(str); i++){
    addRear(&D, str[i]);
  }

  int equal = 1; // flag변수

  while(getCount(&D) > 1 && equal){
    char first = deleteFront(&D);
    char last = deleteRear(&D);
    if (first != last){
      equal = 0;
    }
    if (equal){
      printf("equal");
    }
    else {
      printf("not equal");
    }
  }



  return 0;
}