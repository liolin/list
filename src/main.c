/*
  Author: Olivier Lischer (liolin)
  E-Mail: liolindeb@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
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

void addressListExample()
{
  Address_t c;
  
  printf("Liste erstellen\n");
  List_t *pList = List_init(sizeof(Address_t), addressFree);
  printf("Length: %zu\n", pList->Length);

  printf("============================\n");
  
  printf("Fuege Daten hinzu hinzu\n");
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
  printf("Laenge: %zu\n", pList->Length);
  List_showList(pList, addressShow);
  
  printf("============================\n");

  c = *(Address_t*)List_at(pList, 2);
  printf("Daten bei Index 2\n");
  printf("Name: %s\n", c.name);
  printf("Vname: %s\n", c.vname);

  printf("============================\n");

  printf("Entferne viertes Objekt\n");
  List_delete(pList, 3);
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

void charListExample()
{
  char c;
  
  printf("Liste erstellen\n");
  List_t *pList = List_init(sizeof(char), myFree);
  printf("Length: %zu\n", pList->Length);

  printf("============================\n");
  
  printf("Fuege a,b,c und d hinzu\n");
  c = 'a';
  List_append(pList, &c);
  c = 'b';
  List_append(pList, &c);
  c = 'c';
  List_append(pList, &c);
  c = 'd';
  List_append(pList, &c);
  printf("Laenge: %zu\n", pList->Length);
  List_showList(pList, myShow);
  
  printf("============================\n");

  c = *(char*)List_at(pList, 2);
  printf("Daten bei Index 3: %c\n", c);

  printf("============================\n");

  printf("Entferne erstes Objekt\n");
  List_delete(pList, 0);
  List_showList(pList, myShow);
}


int main()
{
  //charListExample();
  addressListExample();
  return 0;
}
