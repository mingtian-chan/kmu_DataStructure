#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef char element;

typedef struct
{
  element data[N];
  int size;
}ListType;

void init(ListType *L)
{
  L->size = 0;
}

int isEmpty(ListType *L)
{
  return L->size == 0;
}

int isFull(ListType* L)
{
  return L->size == N;
}

void insertLast(ListType* L, element e)
{
  if (isFull(L))
    printf("Full\n");
  else
  {
    L->data[L->size] = e;
    L->size++;
    // 한줄 표현 L->data[L->size++] = e;
  }
}

void insert(ListType* L, int pos, element e)
{
  if (isFull(L))
    printf("Full\n");
  else
  {
    for (int i = L->size - 1; i >= pos; i--)
      L->data[i + 1] = L->data[i];
    L->data[pos] = e;
    L->size++;
  }
}

element delete(ListType *L, int pos) //L의 size - 1, L의 사이즈 -- -> Lastdelete
{
  element data;
  if (pos < 0 || pos >= L->size)
  {
    printf("Invalid Pos");
    return -1;
  }


  data = L->data[pos];
  for (int i = pos; i < (L->size - 1); i++)
    L->data[i] = L->data[i + 1];
  L->size--;

  return data;
}


void print(ListType *L)
{
  for (int i = 0; i < L->size; i++)
    printf("%c", L->data[i]);
  printf("\n");
}



int main()
{
  ListType L;
  init(&L);

  insertLast(&L, 'A'); print(&L);
  insertLast(&L, 'B'); print(&L);
  insertLast(&L, 'C'); print(&L);
  getchar();
  insert(&L, 1, 'D'); print(&L);
  insert(&L, 3, 'E'); print(&L);
  //pos < 0, pos > size check -> insert에서 해줘야됨.
  printf("deleted : [%c]\n", delete(&L, 2));
  print(&L);


  return 0;
}