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
  int size;
}ListType;

void init(ListType *D){
  D-> front = D -> rear = 0;
}
// size로 modulation 해야함.
int isFull(ListType *L){
  return L->size == N;
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

void insertLast(ListType *L, element e){
  if (isFull(L))
    printf("Full\n");
  else{
    L -> data[L->size] = e;
    L -> size++;
  }
}

void insert(ListType *L, int pos, element e){
  if (isFull(L) && pos >=0 && pos <= L-> size){
    for (int i = L -> size - 1; i >= pos; i--)
      L->data[i+1] = L->data[i];
    L->data[pos] = e;
    L->size++;
  }
}


void print(ListType *L){

  for (int i = 0; i < L->size; i++){
    printf("%c",L->data[i]);
  }
  printf("\n");
}

element delete(ListType *L, int pos){
  if (isEmpty(L) || pos < 0 || pos >= L->size){
    printf("ERROR\n");
    return -1;
  }

  element data = L->data[pos];

  for (int i = pos; i < (L->size - 1); i++)
    L->data[i] = L->data[i + 1];
}

// 리스트
int main(){
  ListType L;
  init(&L);




  return 0;
}