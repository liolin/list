/*
  Author: Olivier Lischer (liolin)
  E-Mail: liolindeb@gmail.com

  Last change: 2017-01-28

  Filename: main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct address Address_t;
struct address
{
  char *name;
  char *vname;
};

void addressFree(void *a)
{
  Address_t *addr = (Address_t*)a;
  free(addr);
}

void addressShow(void *a)
{
  Address_t *addr = (Address_t*)a;
  printf("Name: %s\n", addr->name);
  printf("Vorname: %s\n\n", addr->vname);
}

int addressCompare(void *a, void *b)
{
  // replace strcmp thrue strcnmp
  Address_t *x = (Address_t*)a;
  Address_t *y = (Address_t*)b;

  if(strcmp(x->vname,y->vname) < 0)
    return 1;
  else
    return 0;
}

void addressListExample()
{
  Address_t c;
  List_t *pList = List_init(sizeof(Address_t), addressFree);
  c.name = "Burger";
  c.vname = "Flurina";
  List_append(pList, &c);

  c.name = "Lischer";
  c.vname = "Olivier";
  List_append(pList, &c);
  
  c.name = "Lischer";
  c.vname = "Bodo";
  List_append(pList, &c);
  
  c.name = "Burger";
  c.vname = "Simon";
  List_append(pList, &c);
  List_showList(pList, addressShow);

  List_sort(pList, addressCompare);

  printf("\n\n");
  
  List_showList(pList, addressShow);
  List_free(pList);
}


void myFree(void *c)
{
  free((char*)c);
}

void myShow(void *data)
{
  char *c = (char *)data;
  printf("%c\n", *c);
}

int myCompare(void *a, void *b)
{
  char *x = (char*)a;
  char *y = (char *)b;
  return *x < *y ? 1 : 0;
}


void charListExample()
{
  char c;
  List_t *pList = List_init(sizeof(char), myFree);
  c = 'a';
  List_append(pList, &c);
  c = 'c';
  List_append(pList, &c);
  c = 'd';
  List_append(pList, &c);
  c = 'b';
  List_append(pList, &c);
  List_showList(pList, myShow);
  List_sort(pList, myCompare);
  printf("\n\n");
  List_showList(pList, myShow);
}


int main()
{
  //charListExample();
  addressListExample();
  return 0;
}
