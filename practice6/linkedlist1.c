#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
  element data;
  struct ListNode *next;
}ListNode;

typedef struct ListType{
  ListNode *head;
  int size;
}ListType;

void init(ListType *L){
  L->head = NULL;
  L->size = 0;
}

void insertFirst(ListType *L, element e){
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->data = e;
//  젤 앞에 넣으니까 헤드 앞으로 옴
  node->next = L->head;
  L->head = node;
  L->size++;
}

void insertLast(ListType *L, element e){ // 이부분 다시 해보자
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->data = e;
  node->next = NULL; // 이부분 잘 안됐음
  if (L->size ==0)
    L->head = node;
  else{
    ListNode *p;
    for (p = L->head; p->next != NULL; p = p->next);

    p->next = node;
  }
  L->size++;
}
//void deleteLast(ListType *L) {
//  if (L->size == 0){
//    printf("Empty\n");
//    return;
//  }
//  ListNode *p = L->head; // 지우고자 하는 노드 바로 앞 노드
//  ListNode *q = p->next; // 지우고자 하는 노드
//
//  while (q->next != NULL){
//    p = p->next;
//    q = q->next;
//  }
//
//  p->next = NULL;
//  free(q);
//  L->size--;
//}

void insert(ListType *L, int pos, element e){
  if (pos == 1)
    insertFirst(L,e);
  else if(pos == L->size+1)
    insertLast(L,e);
  else{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = L->head;

    for (int i = 1; i < pos - 1 ; i++)
      p = p->next;

    node->data = e;
    node->next = p->next;
    p->next = node;
  }
  L->size++;
}

element deleteFirst(ListType *L){
  if (L->size == 0){
    printf("No element. \n");
    return -1;
  }
  ListNode *p = L->head;
  element e = p->data;
  L->head = p->next;
  free(p);
  L->size--;

  return e;

}

//element deleteLast(ListType *L, int pos){
//
//  if (L->size == 0){
//    printf("No element.\n");
//    return -1;
//  }
//  if (pos < 1 || pos > L->size){
//    printf("Invalid pos");
//  }
//  while (q->next != NULL){
//    p = p->next;
//    q = q->next;
//  }
//
//  p->next = NULL;
//  free(q);
//  L->size--;
//}

element delete(ListType *L, int pos){
  if (pos == 0 || pos > L->size){
    printf("Out of Range\n");
    return -1;
  }
  ListNode *p = L->head;
  ListNode *q;
  element e;

  if (pos == 1)
    e = deleteFirst(L);

//
//  else if (pos == L->size)
//    e = deleteLast(L);


  else {

    for (int i = 1; i < pos - 1; i++) {
      q = p;
      p = p->next;
    }
    e = p->data;
    p = p->next;

    q = p->next;
    q->next = p->next;
    free(p);
  }
  L->size--;
}


void print(ListType *L){
  ListNode *p;
  for (p = L->head; p != NULL; p = p->next){
    printf("%c => ", p->data);
  }
  printf("\b\b\b    \n");
}

int main(){
//  이렇게해도 되지만, 리스트타입을 만듬
//  ListNode *head = NULL;
  ListType L;
  init(&L);
  insertLast(&L, 'E');
  print(&L);

  getchar();

  insertFirst(&L, 'A');
  print(&L);
  insertFirst(&L, 'B');
  print(&L);
  insertLast(&L, 'D');
  print(&L);

  getchar();

  insert(&L,1,'F'); // head에 넣음
  print(&L);
  insert(&L,4,'G'); // 그 중간에 넣음
  print(&L);
  insert(&L,8,'H'); // last에 넣음
  print(&L);

  printf("[%c] was deleted\n", deleteFirst(&L));
  print(&L);

  return 0;
}