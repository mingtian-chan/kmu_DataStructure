#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode{
  element data;
  struct DListNode *prev;
  struct DListNode *next;
}DListNode;

// 이렇게 헤드랑 테일을 묶은 애를 만들어줘
typedef struct DListType{
  DListNode *H;
  DListNode *T;
  int N;
}DListType;

// 아무것도 없는 비어있는 노드를 만들어줌
DListNode* getNode(){
  DListNode *node = (DListNode*)malloc(sizeof(DListNode));
  node -> next = node->prev = NULL;
}

void init(DListType *DL){
  DL->H = getNode();
  DL->T = getNode();
  DL->H->next = DL->T;
  DL->T->prev = DL->H;
  DL->N = 0;
}

void insertFirst(DListType *DL, element e){
  DListNode *node = getNode();
  DListNode *p = DL->H; // 노드라서 헤드를 가르킬 수 있음. 포인터는 안돼

  node->data = e;

  node->prev = p;
  node->next = p->next;

  p->next->prev = node;
  p->next = node;

  DL->N++;
}

// insertLast 는 여러분이 해보시길 바랍니다.
void insertLast(DListType *DL, element e){
  DListNode *node = getNode();
  DListNode *p = DL->T;

  node->data = e;

  node->next = p;
  node->prev = p->prev;

  p->prev->next = node;
  p->prev = node;

  DL->N++;
}

void insert(DListType *DL, int pos, element e) {
  if (pos < 1 || pos > DL->N + 1)
    printf("Invalid Position. \n");

  else {
    if (pos == 1) {
      insertFirst(DL, e);
    }
    else if (pos == (DL->N) + 1) {
      insertLast(DL, e);
    }
    else{
      DListNode *node = getNode();
      DListNode *p = DL->H;

      for (int i = 1; i < pos; i++){
        p = p->next;
      }

      node -> data = e;

      node ->prev  = p;
      node -> next = p->next;

      DL->N++;
    }
  }
}

element delete(DListType *DL, int pos){
  element e = -1;

  if(pos < 1 || pos > DL->N)
    printf("Invalid Position. \n");

  else{
    DListNode *p = DL->H;

    for (int i = 0; i < pos; i++)
      p = p->next;

    e = p->data;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    DL->N--;
  }
  return e;
}

void print(DListType *DL){
  DListNode *p;

  for (p = DL->H->next; p != DL->T; p = p->next){
    printf("[%c] <=> ", p->data);
  }
  printf("\b\b\b\b    \n");
}


int main(){
  DListType DL;
  init(&DL);

  insertFirst(&DL, 'A'); print(&DL);
  insertFirst(&DL, 'B'); print(&DL);

  insertLast(&DL, 'C'); print(&DL);
  insertLast(&DL, 'D'); print(&DL);

  insert(&DL, 1,'E');
  insert(&DL, 6,'F');
  insert(&DL, 5,'G');
  print(&DL);


  return 0;

}