#include "list.h"

/* public functions */
List_t* List_init(size_t elementSize, fn free)
{
  List_t *pList = (List_t*)malloc(sizeof(List_t));
  if(pList == NULL)
    return NULL;

  pList->Length = 0;
  pList->__elements_size = elementSize;
  pList->__free = free;
  pList->pNext = NULL;
  return pList;
}

void List_free(List_t *pList)
{
  while(pList->Length > 0)
    List_delete(pList, 0);
  free(pList);
  pList = 0;
}

int List_append(List_t *pList, void *data)
{
  if(pList == NULL)
    return 1;

  ListNode_t *tmp = pList->pNext;
  ListNode_t *pNew = (ListNode_t*)malloc(sizeof(ListNode_t));
  
  pNew->data = malloc(pList->__elements_size);
  memcpy(pNew->data, data, pList->__elements_size);
  pNew->pNext = NULL;
  
  if(pList->pNext == NULL)
  {
    pList->pNext = pNew;
    pList->Length++;
    return 0;
  }
  
  while(tmp->pNext != NULL)
    tmp = tmp->pNext;
  tmp->pNext = pNew;
  pList->Length++;
  return 0;
}

void* List_at(List_t *pList, size_t index)
{
  if(pList == NULL)
    return NULL;

  ListNode_t *tmp = pList->pNext;
  size_t i = 0;
  while(tmp->pNext != NULL)
  {
    if(i == index)
      return tmp->data;
    tmp = tmp->pNext;
    i++;
  }

  return NULL;
}

int List_delete(List_t *pList, size_t index)
{
  if(pList == NULL)
    return -1;

  ListNode_t *tmp = pList->pNext;
  ListNode_t *pLeft = pList->pNext;
  size_t i = 0;

  if(index == 0)
  {
    tmp = tmp->pNext;
    pList->__free(pLeft->data);
    free(pLeft);

    if(pList->pNext == 0)
    {
      pList->Length = 0;
      return 0;
    }
    
    pList->pNext = tmp;
    pList->Length--;
    return 0;
  }  
  
  while(tmp != NULL)
  {
    if(i == index)
    {
      pLeft->pNext = tmp->pNext;
      pList->__free(tmp->data);
      free(tmp);
      pList->Length--;
      return 0;
    }
    
    pLeft = tmp;
    tmp = tmp->pNext;
    i++;
  }

  return -1;  
}

int List_equal(List_t *pA, List_t *pB)
{
  return pA == pB ? 1 : 0;
}



void List_showList(List_t *pList, fn func)
{
  if(pList == NULL)
    return;

  ListNode_t *tmp = pList->pNext;
  
  while(tmp != NULL)
  {
    (*func)(tmp->data);
    tmp = tmp->pNext;
  }
}
