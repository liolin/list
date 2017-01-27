#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function pointers */
typedef void (*fn)(void*);

/* struct */
typedef struct listNode ListNode_t;
struct listNode
{
  void *data;
  ListNode_t *pNext;
};

typedef struct list List_t;
struct list
{
  size_t Length;
  size_t __elements_size;
  fn __free;
  ListNode_t *pNext;
};


/* public functions */
List_t* List_init(size_t elementSize, fn free);
int List_append(List_t *pList, void * data);
void* List_at(List_t *pList, size_t index);
int List_delete(List_t *pList, size_t index);

/* debug function */
void List_showList(List_t *pList, fn func);

/* private functions */

#endif /* LIST_H */
