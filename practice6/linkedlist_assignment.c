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
  node->next = L->head;
  L->head = node;
  L->size++;
}
void insertLast(ListType *L, element e){
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->data = e;
  node->next = NULL;
  if (L->size == 0)
    L->head = node;
  else{
    ListNode *p;
    for (p = L->head; p->next != NULL; p = p->next);
    p->next = node;
  }
  L->size++;
}
void insert(ListType *L, int pos, element e){
  if (pos == 1)
    insertFirst(L,e);
  else if (pos == L->size+1)
    insertLast(L,e);
  else {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p = L->head;
    for (int i = 1; i < pos - 1; i++)
      p = p->next;
    node->data = e;
    node->next = p->next;
    p->next = node;
  }
  L->size++;
}
void deleteFirst(ListType *L){
  if (L->size == 0){
    printf("Empty\n");
    return;
  }
  ListNode *p = L->head;
  L->head = p->next;
  free(p);
  L->size--;
}
void deleteLast(ListType *L) {
  if (L->size == 0){
    printf("Empty\n");
    return;
  }
  ListNode *p = L->head; // 지우고자 하는 노드 바로 앞 노드
  ListNode *q = p->next; // 지우고자 하는 노드
  while (q->next != NULL){
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  L->size--;
}
void delete(ListType *L, int pos){
  if (pos > L->size){
    printf("Out of Range\n");
    return;
  }
  if (pos == 1)
    deleteFirst(L);
  else if (pos == L->size)
    deleteLast(L);
  else {
    ListNode *p = L->head;
    ListNode *q;
    for (int i = 1; i < pos - 1; i++)
      p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
  }
  L->size--;
}
void print(ListType *L){
  ListNode *p;
  for (p = L->head; p != NULL; p = p->next) {
    printf("%c => ", p->data);
  }
  printf("\b\b\b \n");
}
int main(){
  ListType L;
  init(&L);
  deleteFirst(&L);
  print(&L);
  deleteLast(&L);
  print(&L);
  delete(&L, 2);
  print(&L);
  printf("insert\n");
  printf("------------------------------\n");
  insertLast(&L, 'E');
  print(&L);
  insertFirst(&L, 'A');
  print(&L);
  insertFirst(&L, 'B');
  print(&L);
  insertLast(&L, 'D');
  print(&L);
  insert(&L,1,'F'); // head에 넣음
  print(&L);
  insert(&L,4,'G'); // 그 중간에 넣음
  print(&L);
  insert(&L,8,'H'); // last에 넣음
  print(&L);
  printf("delete\n");
  printf("------------------------------\n");
  deleteFirst(&L);
  print(&L);
  deleteFirst(&L);
  print(&L);
  deleteLast(&L);
  print(&L);
  deleteLast(&L);
  print(&L);
  delete(&L, 2);
  print(&L);
  delete(&L, 2);
  print(&L);
  delete(&L, 1);
  print(&L);
  return 0;
}